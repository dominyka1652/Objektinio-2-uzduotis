## Installation and usage of version v0.1 ##
1. If you do not have codeblocks, download and install it [codeblocks](http://www.codeblocks.org/downloads)
2. Download the chosen release and open the program
3. Press the button F9 to run the program
###### Or use cmd:
1. g++ -c v0.2.cpp
2. g++ -o main v0.2.o
3. main.exe
###
4. Enter the number of students
5. Enter the answer to the question: if you know the number of homeworks type "taip", if not then type "ne".
6. If you choose yes:
     - The program asks you to enter the number of marks
     - Then write the name of student
     - Write the surname of student
     - After these steps the programs asks you if you want to write marks by yourself (write "ivesti") or to generate randomly (write "sugeneruoti"):
       - If you choose to enter marks by yourself write as many grades as you entered before and when you are done write the number 0 and then enter egzam rezult. After these steps input starts again with writing name of a student.
       - If you choose to generate marks randomly, they will appear on the screen and inputs start again with writing name of a student.
7. If you choose no:
    - Program asks you to write the name of student
    - After this write the surname of student
    - After these steps the programs asks you if you want to write marks by yourself (write "ivesti") or to generate randomly (write "sugeneruoti"):
      - If you choose to enter marks by yourself write as many grades as you want and when you are done write the number 0 and then enter egzam rezult. After these steps inputs start again with writing name of a student.
      - If you choose to generate marks randomly, the next step is to enter the number of grades you want to be generated. They will appear on the screen and input starts again with writing name of a student.
8. If you want to get an average write "vidurki", or write "mediana" if you want to get a median.
9. After all inputs the output will appear on the screen: name, surname, average or median.

