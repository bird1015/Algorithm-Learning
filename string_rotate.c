#include <stdio.h>
#include <string.h>

#define MAXLEN 100

//#define DEBUG

#ifdef DEBUG
#define DBG_MSG(...)  printf(__VA_ARGS__)
#else
#define DBG_MSG(...)  
#endif

static inline void swap( char *a , char *b )
{
		char temp;
		
		temp = *a ;
		* a = * b;
		* b = temp ;
}

char *rotate ( char * str , int len , int m)
{
	int i, j, k, r;
	
	k = ( len - m ) - len % m ;
	
	i = 0 ;
	j = m;
	r = len % m ;

	DBG_MSG("k = %d \n", k);

	while (k --)
	{
		swap (&str [ i ], &str[ j ]);
		
		i++;
		j++;
	}

	DBG_MSG("r = %d \n", r);
	
	while (r --)
	{
		int p = j;
		
		while ( p > i )
		{
				swap (&str [p ], &str[ p - 1 ]);
				p--;
		}
		
		i++;
		j++;
	}
      
	return str;
}

void Test_rotate()
{
	int i = 0 ;
	
	printf("%s: \n",__FUNCTION__);
	
	struct T
	{
		char srcStr[ MAXLEN ];
		char dstStr[ MAXLEN ];
		int len;
		int m;
	} 	test [] =
	{
		{ "abcdefghijk" , "defghijkabc" , 11, 3 },
		{ "abcdefghijk" ,"efghijkabcd" , 11, 4 }
	};
	
	if ( 0 == strcmp( test [i ].dstStr , rotate (test [i ].srcStr , test [i ].len , test [i ].m )))
	{
		printf (" TEST CASE %d: PASS! \t" ,i );
		printf ("srcStr = %s \n" , test [i ++]. srcStr);
	}
	else
	{
		printf ("TEST CASE: FAILED! \n" );
	}
	
    if ( 0 == strcmp( test [i ].dstStr , rotate (test [i ].srcStr , test [i ].len , test [i ].m )))
	{
		printf (" TEST CASE %d: PASS! \t" ,i );
		printf ("srcStr = %s \n" , test [i ++]. srcStr);
	}
	else
	{
		printf ("TEST CASE: FAILED! \n" );
	}

}

char *rotate2(char *str, int len , int m)
{
	int i,j,k,r;
	
	k = (len - m) - len % m;
	
	i = 0; 
	j = m;
	
	
	while(1)
	{
		swap(&str[i], &str[j]);
		i++;
		j++;
		if(j < len)
			continue;
		else
			break;
	}
	
	r = len % m;
	
	
	DBG_MSG("r = %d \t j = %d \t i = %d\n",r,j,i);
	
	while(r)
	{
		int p = j - r;
		
		DBG_MSG("str[p] = %c\n",str[p]);
		
		while( p > i)
		{
			swap(&str[p], &str[p-1]);
			p--;
		}
		
		i++;
		r--;
		
	}
	
	return str;
	
}


void Test_rotate2()
{
		int i = 0 ;
		
		printf("%s: \n",__FUNCTION__);

		struct T
		{
			char srcStr[ MAXLEN ];
			char dstStr[ MAXLEN ];
			int len;
			int m;
		} 	test [] =
		{
			{ "abcdefghijk" , "defghijkabc" , 11, 3 },
			{ "abcdefghijk" ,"efghijkabcd" , 11, 4 }
		};

		if ( 0 == strcmp( test [i ].dstStr , rotate2 (test [i ].srcStr , test [i ].len , test [i ].m )))
		{
			printf (" TEST CASE %d: PASS! \t" ,i );
			printf ("srcStr = %s \n" , test [i ++]. srcStr);
		}
		else
		{
			printf ("TEST CASE: FAILED! \n" );
			printf ("srcStr = %s \n" , test [i ++]. srcStr);
		}

		if ( 0 == strcmp( test [i ].dstStr , rotate2 (test [i ].srcStr , test [i ].len , test [i ].m )))
		{
			printf (" TEST CASE %d: PASS! \t" ,i );
			printf ("srcStr = %s \n" , test [i ++]. srcStr);
			
		}
		else
		{
			printf ("TEST CASE: FAILED! \n" );
			printf ("srcStr = %s \n" , test [i ++]. srcStr);
		}

}

int main()
{
  
	Test_rotate();
	
	Test_rotate2 ();


	return 0;
}




