  SELECT /*+ index(customer cust_primary_key_idx) */ sparrow_column1, sparrow_column2 --@violation
  FROM
    sparrow_table