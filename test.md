# factorization

---
## 어떤 내용인가
1보다 큰 32bit unsigned integer 하나를 인자로 받아들여서 소인수분해 나오는 소수들을 작은 수부터 큰 수의 순서대로 한번씩만 출력하는 프로그램을 짜는 내용

---
## 어떻게 풀었나
1. 인자가 하나인지 검사

2. 문자열을 정수형으로 변환
> C 언어에서 표현하는 2진수 8진수 10진수 16진수를 생각하고 정수형만 받을 수 있도록 했다.
> > int a = 숫자 에서 오류가 나지 않는 형태만들 추려서 넣었다고 생각한다.
> > > 놀랍게도 int a = +-+-+0b010010은 정상작동한다.
> 대소문자 구분은 없이 했다.
> 1. 받아들이는 문자열에서 맨 앞에 나오는 white space는 전부 넘기고
> 2. '+'나 '-'가 나올 시 '+'와 '-'가 교대로 나오는 한 전부 다 받아들이고 부호를 정한다.
> 3. 기본은 10진수, 수가 시작되고 0이 맨 앞에 나오면 8진수, 0b나 0B가 맨 앞에 나오면 2진수, 0x나 0X가 맨 앞에 나오면 16진수로 생각하고 정수형으로 바꾼다.
> 4. 숫자 뒤에 붙은 white space도 넘긴다.
> 5. 이후 문자열이 안끝났으면 error
> 6. 1보다 크고 0x100000000보다 작지 않으면 error

3. 정수형으로 변환 됐으면 약수가 될 수 있는 소수들을 구하면서 출력한다.

---
## error 출력 방법
errorcase라는 파일을 만들어 두었고 ft_printerror(x)를 통해 내용을 출력했다.
errorcase에 있는 x번째 줄을 출력한다.
errorcase의 내용을 바꾸면 당연히 출력되는 error의 내용도 바뀐다.

---
## testcase

./factorization 468461
7 66923
./factorization 0x4dDfF
3 5 4253
./factorization 0xffffFFFB
4294967291
./factorization +-+-+0b100000
2

예외처리

인자가 하나가 아닐시
./factorization
This program allows only one argument.
./factorization 54 0615
This program allows only one argument.

음수나 32bit unsigned integer로 표현이 불가능 할 때
./factorization +-+054153
This program only accepts "32bit unsigned integer" greater than 1.
./factorization 0x100000000
This program only accepts "32bit unsigned integer" greater than 1.

8진수에서 8이상의 수
./factorization 0846746
This program allows only one integer that can be expressed in C language to be an argument.

2진수에서 2이상의 수
./factorization 0b10012
This program allows only one integer that can be expressed in C language to be an argument.

소수
./factorization 0.05
This program allows only one integer that can be expressed in C language to be an argument.
