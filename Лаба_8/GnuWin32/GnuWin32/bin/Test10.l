%option main
%{
char *yytext; char c;
%}
%%
[A-Z]		{
			c = *yytext;
           		c = (c + 3 - 0x41) % 26 + 0x41;
			printf("%c",c);
		}
[a-z]		{
			c = *yytext;
           		c = (c + 3 - 0x61) % 26 + 0x61;
			printf("%c",c);
		}
