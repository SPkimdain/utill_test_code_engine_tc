REPORT ZX_DD.

" non-compliant codes
OPEN CURSOR C FOR SELECT * FROM SBOOK WHERE CARRID = 'LH '. "@violation
SELECT * FROM FLIGHTS WHERE FLIGHT_NUMBER = 'LH '. "@violation


" compliant codes
OPEN CURSOR C FOR SELECT * FROM SBOOK WHERE CARRID = 'LH '
  ORDER BY PRIMARY KEY.
SELECT * FROM FLIGHTS WHERE FLIGHT_NUMBER = 'LH ' ORDER BY PRIMARY KEY.