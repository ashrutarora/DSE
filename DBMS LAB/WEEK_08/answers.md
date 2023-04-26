#### 8.1
```
-- Create ACCOUNT table
CREATE TABLE ACCOUNT(
    Account_Number NUMBER(10) CONSTRAINT PK_ACCOUNT PRIMARY KEY,
    Balance NUMBER(10,2) CONSTRAINT MIN_BALANCE CHECK(Balance >= 1000)
);

-- Insert some records into ACCOUNT table
INSERT INTO ACCOUNT VALUES (1001, 1500);
INSERT INTO ACCOUNT VALUES (1002, 2500);
INSERT INTO ACCOUNT VALUES (1003, 1200);
INSERT INTO ACCOUNT VALUES (1004, 3500);

-- Create stored procedure
CREATE OR REPLACE PROCEDURE WITHDRAW_AMOUNT(
    p_Account_Number IN NUMBER,
    p_Withdrawal_Amount IN NUMBER,
    p_Message OUT VARCHAR2
)
AS
    v_Current_Balance NUMBER(10,2);
BEGIN
    SELECT Balance INTO v_Current_Balance
    FROM ACCOUNT
    WHERE Account_Number = p_Account_Number;
    
    IF (v_Current_Balance - p_Withdrawal_Amount >= 1000) THEN
        UPDATE ACCOUNT
        SET Balance = Balance - p_Withdrawal_Amount
        WHERE Account_Number = p_Account_Number;
        
        v_Current_Balance := v_Current_Balance - p_Withdrawal_Amount;
        p_Message := 'Current Balance: ' || v_Current_Balance || '. Withdrawal of ' || p_Withdrawal_Amount || ' is Successful. Updated Current Balance: ' || v_Current_Balance || '.';
    ELSE
        p_Message := 'Current Balance: ' || v_Current_Balance || '. Insufficient fund to withdraw, try with lesser withdrawal amount.';
    END IF;
END;
/
```
##### To call the stored procedure ->
```
DECLARE
    v_Message VARCHAR2(200);
BEGIN
    WITHDRAW_AMOUNT(1001, 500, v_Message);
    DBMS_OUTPUT.PUT_LINE(v_Message);
    
    WITHDRAW_AMOUNT(1002, 3000, v_Message);
    DBMS_OUTPUT.PUT_LINE(v_Message);
    
    WITHDRAW_AMOUNT(1003, 100, v_Message);
    DBMS_OUTPUT.PUT_LINE(v_Message);
    
    WITHDRAW_AMOUNT(1004, 2000, v_Message);
    DBMS_OUTPUT.PUT_LINE(v_Message);
END;
/
```

#### 8.2
```
CREATE OR REPLACE PROCEDURE FIND_AVAILABLE_RESOURCES (
  P_SKILLID IN CHAR(3),
  P_SKILL_EXPERIENCE IN NUMBER
) AS
BEGIN
  FOR emp IN (
    SELECT emp.NAME, emp.PHONE, emp.EMAIL
    FROM EMP emp
    JOIN EMP_SKILL emp_skill ON emp.EMPCODE = emp_skill.EMPNO
    WHERE emp_skill.SKILLID = P_SKILLID
      AND emp_skill.SKILL_EXPERIENCE >= P_SKILL_EXPERIENCE
  ) LOOP
    DBMS_OUTPUT.PUT_LINE('Name: ' || emp.NAME || ', Phone: ' || emp.PHONE || ', Email: ' || emp.EMAIL);
  END LOOP;
END;
/
```
##### To call the stored procedure ->
```
DECLARE
  V_SKILLID CHAR(3) := 'SK1'; -- Replace with the desired skill ID
  V_SKILL_EXPERIENCE NUMBER := 12; -- Replace with the required skill experience
BEGIN
  FIND_AVAILABLE_RESOURCES(V_SKILLID, V_SKILL_EXPERIENCE);
END;
/
```

#### 8.3
```
CREATE OR REPLACE PROCEDURE FIND_ADDITIONAL_BUDGET_NEEDED(P_PRJID IN PRJ_DETAILS.PRJID%TYPE)
IS
  V_DURATION_IN_DAYS NUMBER;
  V_BUDGET_ALLOCATED NUMBER(10,1);
  V_START_DATE PRJ_DETAILS.START_DATE%TYPE;
  V_END_DATE PRJ_DETAILS.END_DATE%TYPE;
  V_ACTUAL_END_DATE PRJ_DETAILS.ACTUAL_END_DATE%TYPE;
  V_PER_DAY_COST NUMBER(10,1);
  V_ADDITIONAL_DAYS NUMBER;
  V_ADDITIONAL_BUDGET NUMBER(10,1);
  V_NAME EMP.NAME%TYPE;
  V_EMAIL EMP.EMAIL%TYPE;
BEGIN
  SELECT START_DATE, END_DATE, ACTUAL_END_DATE, BUDGET_ALLOCATED, LEAD_BY_EMPCODE
  INTO V_START_DATE, V_END_DATE, V_ACTUAL_END_DATE, V_BUDGET_ALLOCATED, V_LEAD_BY_EMPCODE
  FROM PRJ_DETAILS
  WHERE PRJID = P_PRJID;
  
  V_DURATION_IN_DAYS := COALESCE(V_ACTUAL_END_DATE, V_END_DATE) - V_START_DATE;
  
  V_PER_DAY_COST := V_BUDGET_ALLOCATED / V_DURATION_IN_DAYS;
  
  V_ADDITIONAL_DAYS := GREATEST(0, TRUNC(SYSDATE) - TRUNC(V_ACTUAL_END_DATE));
  
  V_ADDITIONAL_BUDGET := V_ADDITIONAL_DAYS * V_PER_DAY_COST;
  
  DBMS_OUTPUT.PUT_LINE('Name of Project Leader:');
  
  SELECT E.NAME, E.EMAIL
  INTO V_NAME, V_EMAIL
  FROM EMP E
  INNER JOIN PRJ_DETAILS P ON E.EMPCODE = P.LEAD_BY_EMPCODE
  WHERE P.PRJID = P_PRJID;
  
  DBMS_OUTPUT.PUT_LINE(V_NAME || ' - ' || V_EMAIL);
  
  SELECT E.NAME, E.EMAIL
  INTO V_NAME, V_EMAIL
  FROM EMP E
  INNER JOIN EMP LE ON E.EMPCODE = LE.LEAD_BY_EMPCODE
  INNER JOIN PRJ_DETAILS P ON LE.EMPCODE = P.LEAD_BY_EMPCODE
  WHERE P.PRJID = P_PRJID;
  
  DBMS_OUTPUT.PUT_LINE('Name & email of Employee to whom Project leader reports to:');
  DBMS_OUTPUT.PUT_LINE(V_NAME || ' - ' || V_EMAIL);
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Project with ID ' || P_PRJID || ' does not exist.');
END;
/
```

##### To call the stored procedure -> 
```
DECLARE
  V_PRJID PRJ_DETAILS.PRJID%TYPE := 'P001';
BEGIN
  FIND_ADDITIONAL_BUDGET_NEEDED(V_PRJID);
END;
/
```

#### 8.4
```
CREATE OR REPLACE FUNCTION get_incentive(project_id IN CHAR)
RETURN NUMBER
IS
  total_incentive NUMBER := 0;
BEGIN
  FOR emp_skill IN (SELECT emp_sk.empno, emp_sk.skill_experience, we.rating
                    FROM emp_skill emp_sk
                    INNER JOIN work_exp we
                    ON emp_sk.empno = we.empcode
                    WHERE we.prjid = project_id)
  LOOP
    IF emp_skill.rating = 'A' THEN
      total_incentive := total_incentive + (30000 * emp_skill.skill_experience);
    ELSIF emp_skill.rating = 'B' THEN
      total_incentive := total_incentive + (20000 * emp_skill.skill_experience);
    ELSIF emp_skill.rating = 'C' THEN
      total_incentive := total_incentive + (10000 * emp_skill.skill_experience);
    END IF;
  END LOOP;

  RETURN total_incentive;
END;
/
```

##### To call the function -> 
```
DECLARE
  project_id CHAR(3) := 'P01';
  incentive NUMBER;
BEGIN
  incentive := get_incentive(project_id);
  DBMS_OUTPUT.PUT_LINE('Total Incentive for Project ' || project_id || ': ' || incentive);
END;
/
```

#### 8.5
```
CREATE OR REPLACE FUNCTION get_clients_by_country_code(p_country_code VARCHAR2)
  RETURN SYS_REFCURSOR IS
  v_clients SYS_REFCURSOR;
BEGIN
  OPEN v_clients FOR
    SELECT NAME FROM CLIENT WHERE PHONE LIKE p_country_code || '-%';
  RETURN v_clients;
END;
/
```

##### To call the function -> 
```
DECLARE
  v_clients SYS_REFCURSOR;
  v_client_name CLIENT.NAME%TYPE;
BEGIN
  v_clients := get_clients_by_country_code('+91');

  LOOP
    FETCH v_clients INTO v_client_name;
    EXIT WHEN v_clients%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE(v_client_name);
  END LOOP;
END;
/
```

#### 8.6
```
CREATE OR REPLACE FUNCTION generate_faculty_email(empno NUMBER, name VARCHAR2) RETURN VARCHAR2
AS
  email VARCHAR2(50);
BEGIN
  email := name || '_' || empno || '@digisol.com';
  RETURN email;
END;
/
```

##### To call the function -> 
```
SELECT generate_faculty_email(101, 'John Doe') as email FROM dual;
```

#### 8.7
```
CREATE OR REPLACE PACKAGE my_package AS

  -- 7.1
  FUNCTION get_report_to_name(empno IN NUMBER) RETURN VARCHAR2;

  -- 7.2
  PROCEDURE display_project_employees(prjid IN CHAR);

  -- 7.3
  PROCEDURE display_projects_from_date(start_date IN DATE);

  -- 7.4
  PROCEDURE display_workforce_details;

  -- 7.5
  FUNCTION count_employees_by_designation(designation IN VARCHAR2) RETURN NUMBER;

END my_package;
/

CREATE OR REPLACE PACKAGE BODY my_package AS

  -- 7.1
  FUNCTION get_report_to_name(empno IN NUMBER) RETURN VARCHAR2 AS
    v_report_to_name employees.name%TYPE;
  BEGIN
    SELECT name INTO v_report_to_name
    FROM employees
    WHERE empno = (SELECT mgr FROM employees WHERE empno = empno);
    RETURN v_report_to_name;
  END;

  -- 7.2
  PROCEDURE display_project_employees(prjid IN CHAR) AS
    CURSOR emp_cur IS
    SELECT e.name, e.empno
    FROM employees e
    JOIN work_exp w ON e.empno = w.empno
    JOIN prj_details p ON p.prjid = w.prjid
    WHERE p.prjid = prjid;
  BEGIN
    DBMS_OUTPUT.PUT_LINE('Employees working on project ' || prjid || ':');
    FOR emp_rec IN emp_cur LOOP
      DBMS_OUTPUT.PUT_LINE(emp_rec.name || ' (Employee ID: ' || emp_rec.empno || ')');
    END LOOP;
  END;

  -- 7.3
  PROCEDURE display_projects_from_date(start_date IN DATE) AS
    CURSOR prj_cur IS
    SELECT prj_name
    FROM prj_details
    WHERE start_date >= start_date;
  BEGIN
    DBMS_OUTPUT.PUT_LINE('Projects starting from ' || start_date || ':');
    FOR prj_rec IN prj_cur LOOP
      DBMS_OUTPUT.PUT_LINE(prj_rec.prj_name);
    END LOOP;
  END;

  -- 7.4
  PROCEDURE display_workforce_details AS
    CURSOR skill_cur IS
    SELECT skillname
    FROM skill;
    emp_cur employees%ROWTYPE;
  BEGIN
    FOR skill_rec IN skill_cur LOOP
      DBMS_OUTPUT.PUT_LINE('Employees with skill ' || skill_rec.skillname || ':');
      FOR emp_cur IN (
        SELECT e.empno, e.name, es.skill_experience
        FROM employees e
        JOIN emp_skill es ON e.empno = es.empno
        JOIN skill s ON es.skillid = s.skillid
        WHERE s.skillname = skill_rec.skillname
      ) LOOP
        DBMS_OUTPUT.PUT_LINE('Employee ID: ' || emp_cur.empno || ', Name: ' || emp_cur.name || ', Skill Experience: ' || emp_cur.skill_experience);
      END LOOP;
    END LOOP;
  END;

  -- 7.5
  FUNCTION count_employees_by_designation(designation IN VARCHAR2) RETURN NUMBER AS
    v_count NUMBER;
  BEGIN
    SELECT COUNT(*) INTO v_count
    FROM employees
    WHERE designation = designation;
    RETURN v_count;
  END;

END my_package;
/
```
