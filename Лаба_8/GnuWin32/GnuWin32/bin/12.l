%option noyywrap
%{
char *yytext; short int Num = 0; char c; char *p,kall[5],govno[2];
%}
%%
[%]([0-9]+)		{
			kall[0] = yytext[1];
			kall[1] = yytext[2];
			kall[2] = yytext[3];
			Num = atoi(kall);
			c = (char) Num;
			printf("%c",c);
			}
%%
int main()
{
	yylex();
}