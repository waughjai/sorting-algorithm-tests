#include "general_sort.h"

void selection_sort( int* list, int count )
{
    for ( int i = 0; i < count - 1; ++i )
    {
        int min = i;
        for ( int j = i + 1; j < count; ++j )
        {
            if ( list[ j ] < list[ min ] )
            {
                min = j;
            }
        }
        swap( list, min, i );
    }
}

int main( int argc, char** argv )
{
    profile_sort( selection_sort );
    return 0;
}