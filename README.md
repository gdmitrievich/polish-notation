# Polish notation

***== Разработать программу src/polish_notation.cpp для построения графиков функций, задаваемых произвольными выражениями.***
***Для вычисления значений выражений использовать алгоритм Дейкстры для перевода выражения в польскую нотацию.***
***Исполняемый файл должен храниться в корне в папке build. ==***

## Условия

1. Через консоль задаются следующие параметры:
   - Функция;
   - Размер поля для вывода графика;
   - Область определения;
   - Область значений;
   - Центр координат.
2. Ничего кроме графика выводиться не должно;
3. Значения округляются по правилам математики;
4. Реализовать меню для изменения значений поля и самой функции;
   - Перемещаться между пунктами в режиме 'SELECT';
   - Изменять значение выбранного пункта в режиме 'EDIT';
   - Клавиши управления:
        - q - выход;
        - m - сменить режим;
        - w, d (k, l) - переместиться на пункт выше (SELECT), увеличить значение (EDIT);
        - s, a (j, h) - переместиться на пункт ниже (SELECT), уменьшить значение (EDIT);

## Графика

График должен быть выведен с помощью знаков «Звездочек» для линии графика, « . » для пустых точек и « o » для отображения осей. ==***

## Модули
- Разбор строки выражения и получение списка лексем.
- Перевод в польскую нотацию и вычисление по ней.
- Отрисовка графика в терминале.
- Библиотеки для организации динамических структур данных (стек, список и т.д.).

**List 1.** Reverse Polish notation (RPN), also known as Polish postfix notation or simply postfix notation, is a mathematical notation in which operators follow their operands, in contrast to Polish notation (PN), in which operators precede their operands. It does not need any parentheses as long as each operator has a fixed number of operands.

In computer science, reverse Polish notation is used in stack-oriented programming languages such as Forth, STOIC, PostScript, RPL and Joy.

**List 2.** In computer science, the shunting-yard algorithm is a method for parsing mathematical expressions specified in infix notation. It can produce either a postfix notation string, also known as Reverse Polish notation (RPN), or an abstract syntax tree (AST).

Like the evaluation of RPN, the shunting yard algorithm is stack-based.

Infix expressions are the form of mathematical notation most people are used to, for instance "3 + 4" or "3 + 4 × (2 - 1)". For the conversion there are two text variables (strings), the input and the output.

There is also a stack that holds operators not yet added to the output queue.

To convert, the program reads each symbol in order and does something based on that symbol.

The result for the above examples would be (in Reverse Polish notation) "3 4 +" and "3 4 2 1 - × +", respectively.
The shunting-yard algorithm was later generalized into operator-precedence parsing.

## Возможные операции & функции

- "+"
- "-" (бинарный)
- "*"
- "/"
- "()"
- sin(x)
- cos(x)
- tan(x)
- ctg(x)
- sqrt(x)
- ln(x)