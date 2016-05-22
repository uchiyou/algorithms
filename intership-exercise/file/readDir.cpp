#include <stdio.h>
#include<stdlib.h>
#include <dir.h>
 
int main()
{
long file;
struct _finddata_t find;

_chdir("e:\\");
if((file=_findfirst("*", &find))==-1L)
{
printf("¿Õ°×!\n");
exit(0);
}
printf("%s\n", find.name);
while(_findnext(file, &find)==0)
{
	
if(find.attrib==_A_SUBDIR){
	printf("directory: ");
}else{
	printf("file: ");
}
                        
printf("%s\n", find.name);
}
_findclose(file);
return 0;
}
