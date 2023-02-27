# Employee Management System
This is a database schema for an Employee Management System, which consists of several tables that store information about employees, their skills, projects they work on, their work experience, family dependents, medical policies, and paychecks.

## EMP Table
The EMP table stores information about employees, including their employee code, name, qualification, phone number, email, designation, and salary.

* EMPCODE - the employee code (primary key)
* NAME - the employee name
QUALIFICATION - the employee's qualification (allowed values: 'BTECH', 'MTECH', 'MSC', 'MCA', 'PHD')
PHONE - the employee's phone number
EMAIL - the employee's email address (must end with '@digisol.com')
DESIGNATION - the employee's designation (allowed values: 'DEVELOPER', 'PROJECT LEADER', 'PROJECT MANAGER', 'TECHNICAL HEAD', 'PROJECT DIRECTOR', 'PROJECT LEADER', 'CEO')
SALARY - the employee's salary (must be between 97000 and 300000)
SKILL Table
The SKILL table stores information about skills that employees possess, including their skill ID and name.

SKILLID - the skill ID (unique)
SKILLNAME - the skill name (unique)
EMP_SKILL Table
The EMP_SKILL table stores information about employees' skills and their experience with each skill.

EMPNO - the employee code (foreign key)
SKILLID - the skill ID (foreign key)
SKILL_EXPERIENCE - the employee's experience with the skill (must be greater than 0)
CLIENT Table
The CLIENT table stores information about clients, including their client ID, name, and phone number.

CLIENTID - the client ID (primary key, must start with 'C')
NAME - the client name
PHONE - the client's phone number (must start with '+91-', '+81-', '+31-', '+48-', or '+44-')
PRJ_DETAILS Table
The PRJ_DETAILS table stores information about projects, including their project ID, start and end dates, lead employee code, budget, and actual budget.

PRJID - the project ID (primary key, must start with 'P')
START_DATE - the project start date
END_DATE - the project end date (must be greater than the start date)
ACTUAL_END_DATE - the actual project end date (must be greater than or equal to the end date)
LEAD_BY_EMPCODE - the employee code of the lead for the project (foreign key)
BUDGET_ALLOCATED - the budget allocated for the project
ACTUAL_BUDGET - the actual budget for the project
PRJ_NAME - the project name
WORK_EXP Table
The WORK_EXP table stores information about employees' work experience on projects, including their employee code, project ID, work experience, client ID, and rating.

EMPCODE - the employee code (foreign key)
PRJID - the project ID (foreign key)
WORK_EXPERIENCE - the employee's work experience on the project (must be greater than or equal to 0)
CLIENTID - the client ID (foreign key, can be null)
RATING - the employee's rating for the project (allowed values: 'A', 'B', '
