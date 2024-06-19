
SELECT /*+ PARALLEL(4) */ * INTO customers.cust_first_name, customers.cust_last_name --@violation
FROM sales, customers
WHERE sales.cust_id=customers.cust_id
GROUP BY customers.cust_first_name, customers.cust_last_name