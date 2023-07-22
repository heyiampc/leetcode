# Write your MySQL query statement below
select c.name As Customers
FROM customers c
LEFT JOIN Orders o
ON c.id=o.customerId
where o.id IS NULL