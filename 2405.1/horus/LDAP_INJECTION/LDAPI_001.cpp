//@checker LDAP_INJECTION
#include <stdlib.h>
#include <stdio.h>

#define FIND_DN 0
#define LDAP_SCOPE_BASE 0
#define LDAP_NO_LIMIT 0

struct LDAP {
 /* dummy for a library */
};

struct LDAPMessage {
  /* dummy for a library */
};

struct LDAPControl {
  /* dummy for a library */
};

extern int ldap_search_ext_s(
  LDAP *ld,
  char *base,
  int scope,
  char *filter,
  char *attrs[],
  int attrsonly,
  LDAPControl **serverctrls,
  LDAPControl **clientctrls,
  struct timeval *timeout,
  int sizelimit,
  LDAPMessage **res);


void LDAPI_001_function() {
  char *filter = getenv("filter_string");
  int rc;
  LDAP *ld = NULL;
  LDAPMessage *result;
  rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE, filter,   //@violation LDAP_INJECTION
  NULL, 0, NULL, NULL, LDAP_NO_LIMIT, LDAP_NO_LIMIT, &result);
}

