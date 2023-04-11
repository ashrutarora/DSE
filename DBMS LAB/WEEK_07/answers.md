#### 7.1 Write PL/SQL block to display reverse of a number.
```
SET SERVEROUTPUT ON;

DECLARE
	num NUMBER;
	rev NUMBER := 0;

BEGIN
num := &Enter_Number;

	WHILE (num>0) LOOP
		rev := (rev*10) + MOD(num, 10); 
		num := TRUNC(num/10);
	END LOOP;

	DBMS_OUTPUT.PUT_LINE('The reverse of the number is: ' || rev);
  
END;
/
```


#### 7.2 Write a PL/SQL block to check a given word is palindrome or not.
```
SET SERVEROUTPUT ON;

DECLARE
    word varchar2(50);
    revWord varchar2(50) := '';

BEGIN
    word := &Enter_Word;
    
    FOR i IN REVERSE 1..LENGTH(word) LOOP
        revWord := revWord || SUBSTR(word, i, 1);
    END LOOP;

    IF revWord = word THEN
        DBMS_OUTPUT.PUT_LINE(word || ' is a Palindrome');
    ELSE
        DBMS_OUTPUT.PUT_LINE(word || ' is not a Palindrome');
    END IF;
    
END;
/
```


#### 7.3 Write a PL/SQL block to accept an employee code from the user and display the employee details.
```
SET SERVEROUTPUT ON;

DECLARE
    
  empcode EMP.EMPCODE%TYPE := &Enter_EmpCode;
  name EMP.NAME%TYPE;
  qualification EMP.QUALIFICATION%TYPE;
  phone EMP.PHONE%TYPE;
  email EMP.EMAIL%TYPE;
  designation EMP.DESIGNATION%TYPE;
  salary EMP.SALARY%TYPE;
  reports_to EMP.REPORTS_TO%TYPE;
  
  CURSOR emp_cur IS 
    SELECT NAME, QUALIFICATION, PHONE, EMAIL, DESIGNATION, SALARY, REPORTS_TO
    FROM EMP
    WHERE EMPCODE = empcode;

BEGIN
  OPEN emp_cur;
  
  FETCH emp_cur INTO name, qualification, phone, email, designation, salary, reports_to;
  
  IF emp_cur%FOUND THEN
      
    DBMS_OUTPUT.PUT_LINE('Employee Details: ');
    DBMS_OUTPUT.PUT_LINE('Emp Code: ' || empcode);
    DBMS_OUTPUT.PUT_LINE('Name: ' || name);
    DBMS_OUTPUT.PUT_LINE('Qualification: ' || qualification);
    DBMS_OUTPUT.PUT_LINE('Phone: ' || phone);
    DBMS_OUTPUT.PUT_LINE('Email: ' || email);
    DBMS_OUTPUT.PUT_LINE('Designation: ' || designation);
    DBMS_OUTPUT.PUT_LINE('Salary: ' || salary);
    DBMS_OUTPUT.PUT_LINE('Reports To: ' || reports_to);

  ELSE
    DBMS_OUTPUT.PUT_LINE('Employee with code ' || empcode || ' not found.');
  END IF;
  
  CLOSE emp_cur;
  
END;
/
```


#### 7.4 Write a PL/SQL block to count number of vowels, consonants, numbers and special characters in a sentence.
```
SET SERVEROUTPUT ON;

DECLARE

    sentence VARCHAR2(100) := &Enter_Sentence;
    vowel_count NUMBER := 0;
    consonant_count NUMBER := 0;
    number_count NUMBER := 0;
    special_count NUMBER := 0;
    
BEGIN

    FOR i IN 1..LENGTH(sentence) LOOP
    
        IF UPPER(SUBSTR(sentence, i, 1)) IN ('A', 'E', 'I', 'O', 'U') THEN
            vowel_count := vowel_count + 1;
            
        ELSIF UPPER(SUBSTR(sentence, i, 1)) BETWEEN 'B' AND 'Z' THEN
            consonant_count := consonant_count + 1;
            
        ELSIF SUBSTR(sentence, i, 1) BETWEEN '0' AND '9' THEN
            number_count := number_count + 1;
            
        ELSE
            special_count := special_count + 1;
            
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Vowels: ' || vowel_count);
    DBMS_OUTPUT.PUT_LINE('Consonants: ' || consonant_count);
    DBMS_OUTPUT.PUT_LINE('Numbers: ' || number_count);
    DBMS_OUTPUT.PUT_LINE('Special characters: ' || special_count);
    
END;
/
```


#### 7.5 Write a PL/SQL block to accept an employee code and project id to find the rating obtained on the project. Depending on the rating assign an additional incentive (A-10000, B-5000, C- 3000). Display the information in the following format:
* Employee Number:
* Employee Name:
* Salary:
* Project Name:
* Rating:
* Incentive:
* Total Salary: Salary+(A-10000, B-5000, C- 3000)
* Update the Other_incentive of employee in Pay_check depending on rating

```
SET SERVEROUTPUT ON;

DECLARE

  v_empcode EMP.EMPCODE%TYPE;
  v_prjid PRJ_DETAILS.PRJID%TYPE;
  v_empname EMP.NAME%TYPE;
  v_salary EMP.SALARY%TYPE;
  v_prjname PRJ_DETAILS.PRJ_NAME%TYPE;
  v_rating WORK_EXP.RATING%TYPE;
  v_incentive NUMBER;
  v_total_salary NUMBER;
  v_other_incentive PAY_CHECK.OTHER_INCENTIVES%TYPE;
  
BEGIN

  -- Assign employee code and project id
  v_empcode := 102;
  v_prjid := 'P2';

  -- Retrieve employee details
  SELECT NAME, SALARY INTO v_empname, v_salary
  FROM EMP
  WHERE EMPCODE = v_empcode;

  -- Retrieve project details
  SELECT PRJ_NAME INTO v_prjname
  FROM PRJ_DETAILS
  WHERE PRJID = v_prjid;

  -- Retrieve project rating
  SELECT RATING INTO v_rating
  FROM WORK_EXP
  WHERE EMPCODE = v_empcode AND PRJID = v_prjid;

  -- Assign incentive based on rating
  CASE v_rating
  
    WHEN 'A' THEN v_incentive := 10000;
    WHEN 'B' THEN v_incentive := 5000;
    WHEN 'C' THEN v_incentive := 3000;
    ELSE v_incentive := 0;
    
  END CASE;

  -- Calculate total salary
  v_total_salary := v_salary + v_incentive;

  -- Update Other_incentive in Pay_check table
  UPDATE PAY_CHECK
  SET OTHER_INCENTIVES = v_incentive
  WHERE EMPCODE = v_empcode;

  -- Display employee details
  DBMS_OUTPUT.PUT_LINE('Employee Number: ' || v_empcode);
  DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_empname);
  DBMS_OUTPUT.PUT_LINE('Salary: ' || v_salary);
  DBMS_OUTPUT.PUT_LINE('Project Name: ' || v_prjname);
  DBMS_OUTPUT.PUT_LINE('Rating: ' || v_rating);
  DBMS_OUTPUT.PUT_LINE('Incentive: ' || v_incentive);
  DBMS_OUTPUT.PUT_LINE('Total Salary: ' || v_total_salary);

END;
/
```


#### 7.6 Write a PL/SQL block to calculate Jan-2021 monthly salary of employee and other components of salary depending on Salary values in EMP table for the employee number 100. Display the salary information of employee 100 in the following format :
```
SET SERVEROUTPUT ON;

DECLARE
    
    v_name EMP.NAME%TYPE;
    v_salary EMP.SALARY%TYPE;
    v_increment PAY_CHECK.REGULAR_INCREMENT%TYPE;
    v_performance_incentive PAY_CHECK.PERFORMANCE_INCENTIVE%TYPE;
    v_da PAY_CHECK.DA%TYPE;
    v_pf PAY_CHECK.PF%TYPE;
    v_other_incentives PAY_CHECK.OTHER_INCENTIVES%TYPE;
    v_advance_tax PAY_CHECK.ADVANCE_TAX%TYPE;
    v_gross_salary NUMBER(10,2);
    v_take_home_salary NUMBER(10,2);

BEGIN
    
    -- Get employee information from EMP table
    SELECT NAME, SALARY
    INTO v_name, v_salary
    FROM EMP
    WHERE EMPCODE = 100;
    
    -- Get regular increment from PAY_CHECK table
    SELECT REGULAR_INCREMENT
    INTO v_increment
    FROM PAY_CHECK
    WHERE EMPCODE = 100
    AND PAY_DATE = '01-JAN-2021';
    
    -- Get performance incentive from PAY_CHECK table
    SELECT PERFORMANCE_INCENTIVE
    INTO v_performance_incentive
    FROM PAY_CHECK
    WHERE EMPCODE = 100
    AND PAY_DATE = '01-JAN-2021';
    
    -- Calculate DA, PF ,other incentives, advance tax
    v_da := (v_salary + v_increment) * 0.5;
    v_pf := (v_salary + v_increment) * 0.12;
    
    SELECT OTHER_INCENTIVES, ADVANCE_TAX
    INTO v_other_incentives, v_advance_tax
    FROM PAY_CHECK
    WHERE EMPCODE = 100
    AND PAY_DATE = '01-JAN-2021';
    
    -- Calculate gross salary and take home salary
    v_gross_salary := v_salary + v_increment + v_performance_incentive + v_da + v_pf + v_other_incentives;
    v_take_home_salary := v_gross_salary - v_pf - v_advance_tax;
    
    -- Display salary information
    DBMS_OUTPUT.PUT_LINE('Name: ' || v_name);
    DBMS_OUTPUT.PUT_LINE('Basic Salary: ' || v_salary);
    DBMS_OUTPUT.PUT_LINE('Regular Increment: ' || v_increment);
    DBMS_OUTPUT.PUT_LINE('Increased Basic Salary: ' || (v_salary + v_increment));
    DBMS_OUTPUT.PUT_LINE('Performance Incentive: ' || v_performance_incentive);
    DBMS_OUTPUT.PUT_LINE('DA: ' || v_da);
    DBMS_OUTPUT.PUT_LINE('PF: ' || v_pf);
    DBMS_OUTPUT.PUT_LINE('Other Incentives: ' || v_other_incentives);
    DBMS_OUTPUT.PUT_LINE('Advance Tax Paid: ' || v_advance_tax);
    DBMS_OUTPUT.PUT_LINE('Monthly Gross Salary: ' || v_gross_salary);
    DBMS_OUTPUT.PUT_LINE('Monthly Take Home Salary: ' || v_take_home_salary);

END;
/
```


#### 7.7 Do the salary processing of all employees according to the Question 6. (using cursor)
```
SET SERVEROUTPUT ON;

DECLARE
    
  CURSOR c_pay_check IS
    SELECT DISTINCT EMPCODE
    FROM PAY_CHECK
    WHERE PAY_DATE = '01-JAN-2021';
    
  v_empcode PAY_CHECK.EMPCODE%TYPE;
  v_name EMP.NAME%TYPE;
  v_salary EMP.SALARY%TYPE;
  v_increment PAY_CHECK.REGULAR_INCREMENT%TYPE;
  v_performance_incentive PAY_CHECK.PERFORMANCE_INCENTIVE%TYPE;
  v_da PAY_CHECK.DA%TYPE;
  v_pf PAY_CHECK.PF%TYPE;
  v_other_incentives PAY_CHECK.OTHER_INCENTIVES%TYPE;
  v_advance_tax PAY_CHECK.ADVANCE_TAX%TYPE;
  v_gross_salary NUMBER(10,2);
  v_take_home_salary NUMBER(10,2);

BEGIN
    
  -- Loop through all employees in PAY_CHECK table
  FOR i IN c_pay_check LOOP
    
    -- Get employee information from PAY_CHECK table
    v_empcode := i.EMPCODE;
    
    SELECT NAME, SALARY
    INTO v_name, v_salary
    FROM EMP
    WHERE EMPCODE = v_empcode;

    -- Get regular increment from PAY_CHECK table
    SELECT REGULAR_INCREMENT
    INTO v_increment
    FROM PAY_CHECK
    WHERE EMPCODE = v_empcode
    AND PAY_DATE = '01-JAN-2021';

    -- Get performance incentive from PAY_CHECK table
    SELECT PERFORMANCE_INCENTIVE
    INTO v_performance_incentive
    FROM PAY_CHECK
    WHERE EMPCODE = v_empcode
    AND PAY_DATE = '01-JAN-2021';

    -- Calculate DA, PF and other incentives
    v_da := (v_salary + v_increment) * 0.5;
    v_pf := (v_salary + v_increment) * 0.12;

    SELECT OTHER_INCENTIVES, ADVANCE_TAX
    INTO v_other_incentives, v_advance_tax
    FROM PAY_CHECK
    WHERE EMPCODE = v_empcode
    AND PAY_DATE = '01-JAN-2021';

    -- Calculate gross salary and take home salary
    v_gross_salary := v_salary + v_increment + v_performance_incentive + v_da + v_pf + v_other_incentives;
    v_take_home_salary := v_gross_salary - v_pf - v_advance_tax;

    -- Display salary information
    DBMS_OUTPUT.PUT_LINE('Name: ' || v_name);
    DBMS_OUTPUT.PUT_LINE('Basic Salary: ' || v_salary);
    DBMS_OUTPUT.PUT_LINE('Regular Increment: ' || v_increment);
    DBMS_OUTPUT.PUT_LINE('Increased Basic Salary: ' || (v_salary + v_increment));
    DBMS_OUTPUT.PUT_LINE('Performance Incentive: ' || v_performance_incentive);
    DBMS_OUTPUT.PUT_LINE('DA: ' || v_da);
    DBMS_OUTPUT.PUT_LINE('PF: ' || v_pf);
    DBMS_OUTPUT.PUT_LINE('Other Incentives: ' || v_other_incentives);
    DBMS_OUTPUT.PUT_LINE('Advance Tax Paid: ' || v_advance_tax);
    DBMS_OUTPUT.PUT_LINE('Monthly Gross Salary: ' || v_gross_salary);
    DBMS_OUTPUT.PUT_LINE('Monthly Take Home Salary: ' || v_take_home_salary);
    DBMS_OUTPUT.PUT_LINE('--------------------------');

  END LOOP;

END;
/
```


#### 7.8 Create a Table ACCOUNT (Account_Number, Balance) with constraint on Balance that Balance must be more than 1000(minimum balance). Insert few records into the table.
```
CREATE TABLE ACCOUNT (
    Account_Number INT PRIMARY KEY,
    Balance DECIMAL(10,2) CHECK (Balance >= 1000)
);

INSERT INTO ACCOUNT (Account_Number, Balance)
VALUES (1, 2000.00);

INSERT INTO ACCOUNT (Account_Number, Balance)
VALUES (2, 1500.00);

INSERT INTO ACCOUNT (Account_Number, Balance)
VALUES (3, 5000.00);
```

#### Write a PL/SQL block to accept and account number, withdrawal amount from the user. Update the Balance by deducting the withdrawal amount from the balance in the case updated balance is going to be more than minimum balance (1000) otherwise do not update the Balance. In both cases display proper message :
* Case 1:
	* Current Balance: Balance
	* Withdrawal of <Withdrawal_amount> is Successful
 	* Updated Current Balance: Updated balance after withdrawal
	
* Case 2:
	* Current Balance: Balance 
	* Insufficient fund to withdraw, try with lesser withdrawal amount

```
SET SERVEROUTPUT ON;

DECLARE
  v_account_number ACCOUNT.ACCOUNT_NUMBER%TYPE;
  v_withdrawal_amount ACCOUNT.BALANCE%TYPE;
  v_balance ACCOUNT.BALANCE%TYPE;

BEGIN
    
  -- Accept account number and withdrawal amount from user
  v_account_number := &account_number;
  v_withdrawal_amount := &withdrawal_amount;
  
  -- Get the current balance for the account
  SELECT balance
  INTO v_balance
  FROM account
  WHERE account_number = v_account_number;
  
  -- Check if the withdrawal amount is less than or equal to the current balance minus the minimum balance
  IF v_withdrawal_amount <= v_balance - 1000 THEN
    -- Update the balance
    UPDATE account
    SET balance = balance - v_withdrawal_amount
    WHERE account_number = v_account_number;
    

    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || v_balance);
    DBMS_OUTPUT.PUT_LINE('Withdrawal of ' || v_withdrawal_amount || ' is Successful');
    DBMS_OUTPUT.PUT_LINE('Updated Current Balance: ' || (v_balance - v_withdrawal_amount));

  ELSE
    
    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || v_balance);
    DBMS_OUTPUT.PUT_LINE('Insufficient fund to withdraw, try with lesser withdrawal amount.');

  END IF;

END;
/
```


#### 7.9 Write a PL/SQL block to display- Name of the project leader, Name of the projects handled for which budget is managed well within the Budget allocated.
```
SET SERVEROUTPUT ON;

DECLARE
  v_lead_name EMP.NAME%TYPE;
  v_prj_name PRJ_DETAILS.PRJ_NAME%TYPE;

BEGIN
    
  FOR i IN 
    (SELECT e.NAME, p.PRJ_NAME
    FROM PRJ_DETAILS p LEFT OUTER JOIN EMP e ON p.LEAD_BY_EMPCODE = e.EMPCODE
    WHERE p.ACTUAL_BUDGET <= p.BUDGET_ALLOCATED) LOOP
    
        v_lead_name := i.NAME;
        v_prj_name := i.PRJ_NAME;
        DBMS_OUTPUT.PUT_LINE('Project Leader: ' || v_lead_name || ', Project Name: ' || v_prj_name);

  END LOOP;

END;
/
```


#### 7.10 Write a PL/SQL block to display the employees name and generate their email id in following format and display the same for all employees :
* Name:
* Designation:
* Email Generated: Name.Designation@digisoul.com

 ```
 SET SERVEROUTPUT ON;

DECLARE
  v_name EMP.NAME%TYPE;
  v_email varchar2(100);
  v_desig EMP.DESIGNATION%TYPE;

BEGIN
    
  FOR i IN 
    (SELECT NAME, EMAIL, DESIGNATION
    FROM EMP) LOOP
    
        v_name := i.NAME;
		v_desig := i.DESIGNATION;
        v_email := i.NAME || '.' || i.DESIGNATION || '@' || 'digisoul.com';

        DBMS_OUTPUT.PUT_LINE('Name: ' || v_name);
		DBMS_OUTPUT.PUT_LINE('Designation: ' || v_desig);
		DBMS_OUTPUT.PUT_LINE('Email: ' || LOWER(v_email));
		DBMS_OUTPUT.PUT_LINE('-----------------------X---------------------------');

  END LOOP;

END;
/
 ```
 
 
 #### 7.11 Write the PL/SQL block for Question 7.8. along with exception handling for
* Entry of not existing Account number.

 ```
SET SERVEROUTPUT ON;

DECLARE
  v_account_number ACCOUNT.ACCOUNT_NUMBER%TYPE;
  v_withdrawal_amount ACCOUNT.BALANCE%TYPE;
  v_balance ACCOUNT.BALANCE%TYPE;

BEGIN
   
  -- Accept account number and withdrawal amount from user

  v_account_number := &account_number;
  v_withdrawal_amount := &withdrawal_amount;
  
  -- Get the current balance for the account

  SELECT balance
  INTO v_balance
  FROM account
  WHERE account_number = v_account_number;

  -- Check if the withdrawal amount is less than or equal to the current balance minus the minimum balance

  IF v_withdrawal_amount <= v_balance - 1000 THEN

    -- Update the balance

    UPDATE account
    SET balance = balance - v_withdrawal_amount
    WHERE account_number = v_account_number;

    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || v_balance);
    DBMS_OUTPUT.PUT_LINE('Withdrawal of ' || v_withdrawal_amount || ' is Successful');
    DBMS_OUTPUT.PUT_LINE('Updated Current Balance: ' || (v_balance - v_withdrawal_amount));
  ELSE
    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || v_balance);
    DBMS_OUTPUT.PUT_LINE('Insufficient funds to withdraw, please try with a smaller amount.');

  END IF;

EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Account number ' || v_account_number || ' does not exist.');

END;
/
 ```
 
 * If Resulting balance is lesser than minimum Balance.
 ```
 SET SERVEROUTPUT ON;

DECLARE
  v_account_number ACCOUNT.ACCOUNT_NUMBER%TYPE;
  v_withdrawal_amount ACCOUNT.BALANCE%TYPE;
  v_balance ACCOUNT.BALANCE%TYPE;
  excep_userNotFound EXCEPTION;
  excep_insufficientBalance EXCEPTION;

BEGIN
    
  -- Accept account number and withdrawal amount from user

  v_account_number := &account_number;
  v_withdrawal_amount := &withdrawal_amount;

  -- Get the current balance for the account
  BEGIN
    SELECT balance
    INTO v_balance
    FROM account
    WHERE account_number = v_account_number;
  EXCEPTION
    WHEN NO_DATA_FOUND THEN
      RAISE excep_userNotFound;
  END;

  -- Check if the withdrawal amount is less than or equal to the current balance minus the minimum balance

  IF v_withdrawal_amount <= v_balance - 1000 THEN

    -- Update the balance

    UPDATE account
    SET balance = balance - v_withdrawal_amount
    WHERE account_number = v_account_number;

    v_balance := v_balance - v_withdrawal_amount;

    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || v_balance);
    DBMS_OUTPUT.PUT_LINE('Withdrawal of ' || v_withdrawal_amount || ' is Successful');
    DBMS_OUTPUT.PUT_LINE('Updated Current Balance: ' || (v_balance - v_withdrawal_amount));

    -- Check if the resulting balance is less than the minimum balance

    IF v_balance < 1000 THEN
      RAISE excep_insufficientBalance;
    END IF;

  ELSE
    
    DBMS_OUTPUT.PUT_LINE('Current Balance: ' || v_balance);
    DBMS_OUTPUT.PUT_LINE('Insufficient fund to withdraw, try with lesser withdrawal amount.');

  END IF;

EXCEPTION
  WHEN excep_userNotFound THEN
    DBMS_OUTPUT.PUT_LINE('Account number ' || v_account_number || ' does not exist.');
  WHEN excep_insufficientBalance THEN
    DBMS_OUTPUT.PUT_LINE('Withdrawal failed. Minimum balance limit is 1000.');

END;
/ 
 ```
 
 #### 7.12 Assume that we have a new project Marvel and there is need for human resources with skills- 3 full stack developer, 1 Oracle and 1 Azure each having at least 12 months of experience. Pass skill_experience as parameter and list all the human resources available in the company satisfying the need.
 
 ```
 
 ```
 
 
 #### 7.13 Write PL/SQL block with parameterized cursor to display all the employee code, name, designation of the employees who are rated with a particular rating by a particular client. Pass rating and client as parameter to the cursor. (Use cursor for loop.)
 
 ```
 SET SERVEROUTPUT ON;

DECLARE
    
  p_rating WORK_EXP.RATING%TYPE := &Enter_Rating;
  p_client CLIENT.CLIENTID%TYPE := &Enter_CliendID;
  
  -- Parameterized Cursor

  CURSOR c_emp_rating(p_rating WORK_EXP.RATING%TYPE, p_client CLIENT.CLIENTID%TYPE) IS 
      
    SELECT EMPCODE, NAME, DESIGNATION
    FROM EMP NATURAL JOIN WORK_EXP
    WHERE RATING = p_rating AND CLIENTID = p_client;

BEGIN
 -- Feeding value to the parameters in the For Loop
  FOR emp IN c_emp_rating(p_rating, p_client) LOOP
    
    DBMS_OUTPUT.PUT_LINE('Emp Code: ' || emp.EMPCODE || ' | Name: ' || emp.NAME || ' | Designation: ' || emp.DESIGNATION);

  END LOOP;
END;
/
 ```
 
 
 #### 7.14 Write a PL/SQL block to display name, total work experience of 5 employees who are having highest total work experience.
 
 ```
 SET SERVER OUTPUT ON;

DECLARE
    
  CURSOR c_work IS
    
    SELECT e.NAME, SUM(w.WORK_EXPERIENCE) total_work_exp
    FROM EMP e, WORK_EXP w
    WHERE e.EMPCODE = w.EMPCODE
    GROUP BY e.NAME
    ORDER BY total_work_exp DESC
    
    FETCH FIRST 5 ROWS ONLY;

BEGIN
    
  FOR i IN c_work LOOP
    DBMS_OUTPUT.PUT_LINE('Employee Name: ' || i.NAME);
	DBMS_OUTPUT.PUT_LINE('Total Work Experience: ' || i.total_work_exp);
	DBMS_OUTPUT.PUT_LINE('---------------X---------------');
  END LOOP;
END;
/
 ```
