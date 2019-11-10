#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBER_OF_TESTS 50
#define NUMBER_OF_ELEMENTS 50

void print_list( int* list, int count )
{
    int i = 0;
    while ( i < count - 1 )
    {
        printf( "%d, ", list[ i ] );
        ++i;
    }
    printf( "%d\n", list[ i ] );
}

void randomize_list( int* list, int count )
{
    srandom( time( 0 ) );
    for ( int i = 0; i < count; ++i )
    {
        list[ i ] = random() % 10;
    }
}

void test_sort( void ( *sorter )( int*, int ) )
{
    int list[ NUMBER_OF_ELEMENTS ] = { 0 };
    randomize_list( list, NUMBER_OF_ELEMENTS );
    printf( "Original List:\n" );
    print_list( list, NUMBER_OF_ELEMENTS );

    sorter( list, NUMBER_OF_ELEMENTS );

    printf( "New List:\n" );
    print_list( list, NUMBER_OF_ELEMENTS );
}

void profile_sort( void ( *sorter )( int*, int ) )
{
    int list[ NUMBER_OF_ELEMENTS ] = { 0 };
    double min = 9999.99;
    double max = 0.0;
    double sum = 0.0;
    for ( int i = 0; i < NUMBER_OF_TESTS; ++i )
    {
        randomize_list( list, NUMBER_OF_ELEMENTS );
        clock_t begin = clock();
        sorter( list, NUMBER_OF_ELEMENTS );
        clock_t end = clock();
        double time_spent = ( double )( end - begin ) / CLOCKS_PER_SEC;
        if ( time_spent < min )
        {
            min = time_spent;
        }
        if ( time_spent > max )
        {
            max = time_spent;
        }
        sum += time_spent;
    }
    double average = sum / NUMBER_OF_TESTS;
    printf( "AVG: %f\n", average );
    printf( "MAX: %f\n", max );
    printf( "MIN: %f\n", min );
}