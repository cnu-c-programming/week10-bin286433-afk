#include <stdio.h>
#include <string.h>

struct IPv4 {
    unsigned int version;
    unsigned int ihl;
    unsigned long long ttl;
    unsigned long long protocol;
    unsigned char data[1024];
};

void update_val(struct IPv4 s){
    sprintf(s.data, "update_val");
}

void updata_ptr(struct IPv4* s){
    sprintf(s->data, "updata_ptr");
}

int main() {
   struct IPv4 s1, s2 = {0};
   update_val(s1);
   updata_ptr(&s2);
   printf("%s\n", s1.data);
   printf("%s\n", s2.data);
}
