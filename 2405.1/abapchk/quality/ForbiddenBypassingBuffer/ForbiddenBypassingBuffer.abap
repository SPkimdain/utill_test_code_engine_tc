REPORT ZX_DD.

" non-compliant codes
SELECT lastname
INTO US_PERSONS
FROM PERSONS  "@violation
BYPASSING BUFFER
WHERE CITY EQ 'US'.

" compliant codes
SELECT *
INTO US_PERSONS
FROM PERSONS
WHERE CITY EQ 'US'.