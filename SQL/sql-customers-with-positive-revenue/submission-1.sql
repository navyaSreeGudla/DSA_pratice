-- Write your query below
SELECT customer_id
FROM customers  AS c
WHERE c.revenue>0 AND c.year = 2020
GROUP BY customer_id