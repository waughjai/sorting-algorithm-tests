#define swap( list, i, j )\
    int t = list[ i ];\
    list[ i ] = list[ j ];\
    list[ j ] = t

void test_sort( void ( *sorter )( int*, int ) );
void profile_sort( void ( *sorter )( int*, int ) );