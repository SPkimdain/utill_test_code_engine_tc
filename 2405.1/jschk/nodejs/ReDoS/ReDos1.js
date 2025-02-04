'use strict';

const safe = require('safe-regex')
const _ = require('lodash');
const safe_regex = require('safe-regex');
const moment = require('moment');
const path = require('path');
const CommonUtil = {
  escapeStringRegexp: function(str) {
    return String(str) //@violation
		.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&');
  },
  TestRegexp: function(str) {
      return String(str)
  		.replace(safe_regex(/[-\/\\^$*+?.()|[\]{}]/g), '\\$&');
    },
  decimals2: function (number) {
    number = number || 0;
    return Math.round(number * 100) / 100;
  },
  decimals3: function (number) {
    number = number || 0;
    return Math.round(number * 1000) / 1000;
  },
  trimChars(text, char) {
    let re = new RegExp('^[' + char + ']+|[' + char + ']+$', 'g'); //@violation
    return text.replace(re, '');
  },
  // Return array of string values, or NULL if CSV string not well formed.
  convertCSVToArray(text) {
    if (!text) {
      return;
    }
    return text.match(/(".*?"|[^",\s]+)(?=\s*,|\s*$")/g); //@violation
  },
  getHeadersFromText(text) {
    var labels = this.convertCSVToArray(text);
    var headers = [];
    labels.forEach((item, index) => {
      labels[index] = this.trimChars(item, '"');
      if (labels[index]) {
        let headerCode = labels[index].toLowerCase().split(' ').join('_');
        headers.push({ headerName: labels[index], headerCode: headerCode, index: index });
      }
    });
    return headers;
  }
};

module.exports = CommonUtil;