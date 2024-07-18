#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
	float realpart; /* 实部 */
	float imagpart; /* 虚部 */

}Complex; /* 定义复数抽象类型 */

void assign(Complex* A, float real, float imag); /* 赋值 */
void add(Complex* c, Complex A, Complex B); /* A + B */
void minus(Complex* c, Complex A, Complex B); /* A- B */
void multiply(Complex* c, Complex A, Complex B); /* A * B */
Complex divide(Complex* c, Complex A, Complex B); /* A / B */
void GetReal(Complex* z, float RealPart);
void GetImag(Complex* z, float ImagPart);
void main()
{
	Complex* z1, * z2, * z3, * z4, * z;
	z1 = (Complex*)malloc(sizeof(Complex));
	z2 = (Complex*)malloc(sizeof(Complex));
	z3 = (Complex*)malloc(sizeof(Complex));
	z4 = (Complex*)malloc(sizeof(Complex));
	z = (Complex*)malloc(sizeof(Complex));
	float RealPart = 0, ImagPart = 0;
	assign(z1, 8.0, 6.0); // 构造复数 z1
	assign(z2, 4.0, 3.0); // 构造复数 z2
	add(z3, *z1, *z2); // 两个复数相加
	multiply(z4, *z1, *z2); // 两个复数相乘
	if (z3->realpart != 0 || z3->imagpart != 0)
	{
		divide(z, *z4, *z3);
	}
	GetReal(z, RealPart);
	GetImag(z, ImagPart);

}
void assign(Complex* A, float real, float imag)
{
	A->realpart = real; /* 实部赋值 */
	A->imagpart = imag; /* 虚部赋值 */
}  /* End of assign() */

void add(Complex* c, Complex A, Complex B) /* c = A + B */
{
	c->realpart = A.realpart + B.realpart; /* 实部相加 */
	c->imagpart = A.imagpart + B.imagpart; /* 虚部相加 */
} /* End of add() */
void minus(Complex* c, Complex A, Complex B) /* c = A - B */
{
	c->realpart = A.realpart - B.realpart; /* 实部相减 */
	c->imagpart = A.imagpart - B.imagpart; /* 虚部相减 */
} /* End of minus() */
void multiply(Complex* c, Complex A, Complex B)  /* c = A * B */
{
	c->realpart = A.realpart * B.realpart - A.imagpart * B.imagpart;
	c->imagpart = A.realpart * B.imagpart + A.imagpart * B.realpart;
} /* End of multiply() */
Complex divide(Complex* c, Complex A, Complex B) /* c = A * B */
{
	c->realpart = (A.realpart * B.realpart + A.imagpart * B.imagpart) / (B.realpart * B.realpart + B.imagpart * B.imagpart);
	c->imagpart = (A.imagpart * B.realpart - A.realpart * B.imagpart) / (B.realpart * B.realpart + B.imagpart * B.imagpart);
	return *c;
} /* End of divide() */
void GetReal(Complex* z, float RealPart)
{
	RealPart = z->realpart;
	printf("%f\n", RealPart);
}
void GetImag(Complex* z, float ImagPart)
{
	ImagPart = z->imagpart;
	printf("%f\n", ImagPart);
}
