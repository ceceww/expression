#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>

// In this exercise you will implement storing and evaluation 
// of simple arithmetic expressions using inheritance.
// 
// The hierarchy of expressions is:
//
//                  				Expression
//                       				 |
//             --------------------------------------------------
//             |                         |                      |
//        BinaryExpression              Number              UnaryExpression
//             |                                                |
//  ------------------------                            ----------------
//  |                      |                            |              |
// Multiply               Add                          Square         Abs
//
//
// Number represents expressions that are integer values,
// Multiply represents multiplication of two Expressions,
// Add represents sum of two Expressions, and
// Abs represents the absolute value of an Expression.         
// All expressions should support functions:
// type : return the name of the class
// print : return a string version of the entire expression
//         more details below
// evaluate : return the result of evaluating the expression
// The result of evaluating an expression is an integer.
//
// As in Part 1, you should add the virtual keyword where appropriate
// and then implement the functions where they are most appropriate.
// Expression, BinaryExpression, and UnaryExpression could be  abstract 
// classes but all other classes should be concrete classes.


class Expression {
public:
	Expression();
	virtual ~Expression();

	// Functions supported by all types of Expression:
	
	// Returns the result of evaluating the expression.
	virtual int evaluate() const;
	
	// Prints the expression.
	// You should NOT introduce extra spaces or new lines.
	// The brackets and the corresponding operator are part
	// of the output format and do not depend on the 
	// contents of the expression. Required format:
	//
	// Multiply: 
	// (subexp*subexp)
	//           
	// Add:
	// (subexp+subexp)
	//     
	// Abs:
	// Abs(subexp)
	//    
	// Square:
	// Square(subexp)
	//	
	// Number, where n is its value:
	// n
	virtual std::string print() const;

	// Returns the name of the class:
	// Multiply, Add, Number, Square or Abs
	virtual std::string type() const;
};


class BinaryExpression : public Expression {
public:
	BinaryExpression() = delete;
	BinaryExpression(Expression* subexp1, Expression* subexp2);
	~BinaryExpression();

protected:
	Expression* exp1;
	Expression* exp2;
};

class UnaryExpression : public Expression {
public:
	UnaryExpression() = delete;
	UnaryExpression(Expression* subexp);
	~UnaryExpression();

protected:
	Expression* exp;
};


class Number : public Expression {
public:
	Number() = delete;
	Number(int n);
	~Number();

	int evaluate() const;
	std::string print() const;
	std::string type() const;

protected:
	int num;
};


class Multiply : public BinaryExpression {
public:
	Multiply() = delete;
	Multiply(Expression* subexp1,Expression* subexp2);
	~Multiply();

	// Override virtual functions
	int evaluate() const;
	std::string print() const;
	std::string type() const;

private:
	Expression result;
};

class Add : public BinaryExpression{
public:
	Add() = delete;
	Add(Expression* subexp1,Expression* subexp2);
	~Add();

	// Override virtual functions
	int evaluate() const;
	std::string print() const;
	std::string type() const;

private:
	Expression result;
};


class Abs : public UnaryExpression {
public:
	Abs() = delete;
	Abs(Expression* subexp);
	~Abs();

	// Override virtual functions
	int evaluate() const;
	std::string print() const;
	std::string type() const;

private:
	Expression result;
};

class Square : public UnaryExpression {
public:
	Square() = delete;
	Square(Expression* subexp);
	~Square();

	// Override virtual functions
	int evaluate() const;
	std::string print() const;
	std::string type() const;

private:
	Expression result;
};

#endif /* EXPRESSION_H_ */
