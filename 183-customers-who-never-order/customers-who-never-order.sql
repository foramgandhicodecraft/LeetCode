# Write your MySQL query statement below
select name as Customers
from Customers
left join Orders
on customers.id = customerId
where customerId is NULL;