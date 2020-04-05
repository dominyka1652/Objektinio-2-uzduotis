### Usage of a v0.2 version

1. If you do not have codeblocks, download and install it [codeblocks](http://www.codeblocks.org/downloads)
2. Download the chosen release and open the program
3. Press the button F9 to run the program
###### Or use cmd:
1. g++ -c v0.2.cpp
2. g++ -o main v0.2.o
3. main.exe
####
1. Enter "ivesti" if you want to enter data manually or "nuskaityti" if you want it to be read from a file
2. if you choose to read information from a file:
    - Enter the name of a input file
    - In a next step enter the number of homework marks that is written in a file
    - Then write "vidurki" if you want to get a average of grades or "mediana" if you want to get median. After this a file named "Rezultatai" will be created in the same location as your program. 
3. If you choose to enter data manually:
    - Enter the number of students 
    - Enter the answer to the question: if you know the number of homeworks type "taip", if not then type "ne".
4. If you choose yes:    
    - The program asks you to enter the number of marks
    - Write the surname of student
    - Then write the name of student
    - After these steps the programs asks you if you want to write marks by yourself (write "ivesti") or to generate randomly (write "sugeneruoti"):
      - If you choose to enter marks by yourself write as many grades as you entered before and when you are done write the number 0 and then enter egzam rezult. After these steps input starts again with writing name of a student.
      - If you choose to generate marks randomly, they will appear on the screen and inputs start again with writing name of a student.
    - when you are done with input the program asks you if you want to get a average (enter "vidurki") or a median (enter "mediana" and the output file will be created
5. If you choose no:
     - Program asks you to write the name of student
     - After this write the surname of student
     - After these steps the programs asks you if you want to write marks by yourself (write "ivesti") or to generate randomly (write "sugeneruoti")
       - If you choose to enter marks by yourself write as many grades as you want and when you are done write the number 0 and then enter egzam rezult. After these steps input starts again with writing name of a student.
       - If you choose to generate marks randomly, the next step is to enter the number of grades you want to be generated. They will appear on the screen and input starts again with writing name of a student.
    - when you are done with input the program asks you if you want to get a average (enter "vidurki") or a median (enter "mediana" and the output file will be created
