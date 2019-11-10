#include "general_sort.h"

void bubble_sort( int* list, int count )
{
    for ( int i = count - 1; i >= 0; --i )
    {
        for ( int j = 1; j <= i; ++j )
        {
            if ( list[ j - 1 ] > list[ j ] )
            {
                swap( list, j - 1, j );
            }
        }
    }
}

int main( int argc, char** argv )
{
    profile_sort( bubble_sort );
    return 0;
}