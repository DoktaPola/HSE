#ifndef KPO_TASK1_H
#define KPO_TASK1_H
#include <string>

struct Person {
    std::string name;
    unsigned age;
};

int comp1( const void* a, const void* b );
int comp2( const void* a, const void* b );
int comp3( const void* a, const void* b );
int comp4( const void* a, const void* b );
int comp5( const void* a, const void* b );
int comp6( const void* a, const void* b );

#endif //KPO_TASK1_H