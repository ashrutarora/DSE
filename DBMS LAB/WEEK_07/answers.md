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
```

#### 7.2 Write a PL/SQL block to check a given word is palindrome or not.
```
SET SERVEROUTPUT ON;

DECLARE
    word varchar2(50);
    revWord varchar2(50) := '';
    origWord varchar2(50);

BEGIN
    word := &Enter_Word;
    origWord := word;
    
    FOR i IN REVERSE 1..LENGTH(word) LOOP
        revWord := revWord || SUBSTR(word, i, 1);
    END LOOP;

    IF revWord = origWord THEN
        DBMS_OUTPUT.PUT_LINE(origWord || ' is a Palindrome');
    ELSE
        DBMS_OUTPUT.PUT_LINE(origWord || ' is not a Palindrome');
    END IF;
    
END;
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

```
