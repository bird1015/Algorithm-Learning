#include<iostream>
#include<cmath>
using namespace std ;
class queen
{
       public :
      
             queen (){};
             //queen(int row = -1, int col = -1) : m_row(row), m_col(col) {}
            
             void setRow( int row) { m_row = row ; }
             void setCol( int col) { m_col = col ; }
            
             int getCol() const {return m_col ; }
             int getRow() const {return m_row ; }
            
       private :
      
             int m_row;
             int m_col;
};

// curr : 当前的皇后序号（第几个皇后），该值也表明该皇后在第几行
void Queue( queen * nq , int curr , int *sum , int n )
{
       if ( curr == n )
      {
             for (int i = 0 ; i < n ; i ++)
            {
                   cout << nq [i ]. getCol()<< " " ;
            }
             cout <<endl ;
            (* sum )++;
            
             return ;
      }
       int i, j;
       for ( i = 0 ; i < n; i++) //  i 表示所有列，依次尝试放在每一列
       {
             for ( j = 0 ; j < curr; j++) // j 代表已经放下的皇后
             {
                   //if( abs(nq[j].getCol() - nq[i].getCol()) == abs(nq[j].getRow() - nq[i].getRow()) || nq[i].getCol() == nq[j].getCol())
                   if ( abs (nq [j ]. getCol() - i) == abs (nq [j ].getRow () - curr ) || nq [j ].getCol () == i)
                         break ;
            }
             if ( j == curr ) // 可以放下，和前 curr - 1 个皇后都不冲突
            {
                   nq[ curr ].setCol (i );
                   Queue (nq , curr + 1 , sum , n );
            }
      }
}

int nqueenP( int n)
{
       queen * nq = new queen [n ];
      

       for (int i = 0 ; i < n ; i ++)
      {
             nq[ i]. setRow (i );
             nq[ i]. setCol (0 );
      }
      
       int sum = 0 ;
      
       Queue (nq ,0 ,&sum ,n );
      
       return sum ;
}


int main()
{
       cout <<"8 Queue Result: " << nqueenP( 8 )<<endl ;
}

