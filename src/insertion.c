#include "general_sort.h"

void insertion_sort( int* list, int count )
{
    for ( int i = 1; i < count; ++i )
    {
        int value = list[ i ];
        int j = i;
        while ( j > 0 && list[ j - 1 ] > value )
        {
            list[ j ] = list[ j - 1 ];
            --j;
        }
        list[ j ] = value;
    }
}

int main( int argc, char** argv )
{
    profile_sort( insertion_sort );
    return 0;
}