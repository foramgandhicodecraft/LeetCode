# Write your MySQL query statement below
select department.name as Department, employee.name as Employee, salary as Salary
from employee
join department
on departmentId = department.id
where salary = (
    select max(salary) from employee
    where departmentId = department.id
)
