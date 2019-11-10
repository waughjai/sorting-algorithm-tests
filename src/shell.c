#include "general_sort.h"

void shell_sort( int* list, int count )
{
    int h = 1;
    do
    {
        h = 3 * h + 1;
    } while ( h <= count );
    int j;
    int value;

    while ( h != 1 )
    {
        h = ( int )( ( double )( h ) / 3 );
        for ( int i = h + 1; i < count; ++i )
        {
            value = list[ i ];
            j = i;
            while ( list[ j - h ] > value )
            {
                list[ j ] = list[ j - h ];
                j -= h;
                if ( j<= h )
                {
                    goto SHELL_SORT_END;
                }
            }
        }

        SHELL_SORT_END:
            list[ j ] = value;
    }
}

int main( int argc, char** argv )
{
    test_sort( shell_sort );
    return 0;
}