#include <algorithm>
#include <iostream>
#include <string>
#include <omp.h>
#include <stdlib.h>

#define STATIC 1
#define DYNAMIC 2
#define GUIDED 3
#define RUNTIME 4
#define AUTO 5

class SharedArray {
private:
   char* array;
   int index;
   int size;
public:
   SharedArray(int n) : size(n), index(0){
      array = new char[size];
      std::fill(array, array+size, '-');
   }

   void addChar(char c) {
    #pragma omp critical
    {
      array[index] = c;
      spendSomeTime();
      index++;   
    }   
    }

   void addNChar(char c){
      array[index] = c;
      spendSomeTime();
      index++; 
   }

   int countOccurrences(char c) {
      return std::count(array, array+size, c);
   }

   std::string toString() {
      return std::string(array, size);
   }

private:
   void spendSomeTime() {
      for (int i = 0; i < 10000; i++) {
         for (int j = 0; j < 100; j++) {
            // These loops shouldn't be removed by the compiler
         }
      }
   }
};


class ArrayFiller {

private:
   static const int nThreads = 3;
   static const int nTimes = 60;
   SharedArray* array;

public:
   ArrayFiller() {
      array = new SharedArray(nTimes);
   }

   void fillArrayConcurrently(int flag, int ch) {

        switch(flag){
          case STATIC:
            if(ch == 0){           
             #pragma omp parallel for schedule(static) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            }
            else{
                 #pragma omp parallel for schedule(static, ch) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;            
            }
            break;
          case DYNAMIC:
            #pragma omp parallel for schedule(dynamic, ch) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;
          case GUIDED:
            #pragma omp parallel for schedule(guided, ch) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;
          case RUNTIME:
            #pragma omp OMP_SCHEDULE=dynamic
            #pragma omp parallel for schedule(runtime) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;
          case AUTO:
            #pragma omp parallel for schedule(auto) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;


        }
    }


void BadFillArrayConcurrently(int flag, int ch) {

        switch(flag){
          case STATIC:
            if(ch == 0){           
             #pragma omp parallel for schedule(static) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addNChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            }
            else{
                 #pragma omp parallel for schedule(static, ch) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addNChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;            
            }
            break;
          case DYNAMIC:
            #pragma omp parallel for schedule(dynamic, ch) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addNChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;
          case GUIDED:
            #pragma omp parallel for schedule(guided, ch) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addNChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;
          case RUNTIME:
            #pragma omp OMP_SCHEDULE=dynamic
            #pragma omp parallel for schedule(runtime) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addNChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;
          case AUTO:
            #pragma omp parallel for schedule(auto) num_threads(nThreads)
              for (int i = 0; i < nTimes; ++i){
                 array->addNChar('A' + omp_get_thread_num());
                 //std::cout << "Thread " << omp_get_thread_num() << " Coloca " << i << std::endl; 
              }
            break;


        }
    }

   void printStats() {
      std::cout << array->toString() << std::endl;
      for (int i = 0; i < nThreads; ++i)
         std::cout << (char) ('A'+i) << "=" 
                   << array->countOccurrences('A'+i) << " ";
      std::cout << std::endl;
   }

};


int main() {
   std::cout << "Threads adicionam Chars ao array (nThreads= 3 | tamanho array = 60)" << std::endl;
   std::cout << "Casos com exclusão mútua." << std::endl;
   std::cout << "Case 1: Schedule Static without chunk" << std::endl;
   ArrayFiller m1;
   m1.fillArrayConcurrently(STATIC,0);
   m1.printStats();
   
   std::cout << "Case 2: Schedule Static with chunk " << std::endl;
   ArrayFiller m2;
   m2.fillArrayConcurrently(STATIC,15);
   m2.printStats();
   
   std::cout << "Case 3: Schedule Dynamic without chunk" << std::endl;
   ArrayFiller m3;
   m3.fillArrayConcurrently(DYNAMIC,1);
   m3.printStats();

   std::cout << "Case 4: Schedule Dynamic with chunk" << std::endl;
   ArrayFiller m4;
   m4.fillArrayConcurrently(DYNAMIC,15);
   m4.printStats();

   std::cout << "Case 5: Schedule Guided without chunk" << std::endl;
   ArrayFiller m5;
   m5.fillArrayConcurrently(GUIDED,1);
   m5.printStats();

   std::cout << "Case 6: Schedule Guided with chunk" << std::endl;
   ArrayFiller m6;
   m6.fillArrayConcurrently(GUIDED,15);
   m6.printStats();

   std::cout << "Case 7: Schedule Runtime" << std::endl;
   ArrayFiller m7;
   m7.fillArrayConcurrently(RUNTIME,0);
   m7.printStats();

   std::cout << "Case 8: Schedule Auto" << std::endl;
   ArrayFiller m8;
   m8.fillArrayConcurrently(AUTO,0);
   m8.printStats();

    std::cout << "Casos sem exclusão mútua." << std::endl;

std::cout << "Case 1: Schedule Static without chunk" << std::endl;
   ArrayFiller n1;
   n1.BadFillArrayConcurrently(STATIC,0);
   n1.printStats();
   
   std::cout << "Case 2: Schedule Static with chunk " << std::endl;
   ArrayFiller n2;
   n2.BadFillArrayConcurrently(STATIC,15);
   n2.printStats();
   
   std::cout << "Case 3: Schedule Dynamic without chunk" << std::endl;
   ArrayFiller n3;
   n3.BadFillArrayConcurrently(DYNAMIC,1);
   n3.printStats();

   std::cout << "Case 4: Schedule Dynamic with chunk" << std::endl;
   ArrayFiller n4;
   n4.BadFillArrayConcurrently(DYNAMIC,15);
   n4.printStats();

   std::cout << "Case 5: Schedule Guided without chunk" << std::endl;
   ArrayFiller n5;
   n5.BadFillArrayConcurrently(GUIDED,1);
   n5.printStats();

   std::cout << "Case 6: Schedule Guided with chunk" << std::endl;
   ArrayFiller n6;
   n6.BadFillArrayConcurrently(GUIDED,15);
   n6.printStats();

   std::cout << "Case 7: Schedule Runtime" << std::endl;
   ArrayFiller n7;
   n7.BadFillArrayConcurrently(RUNTIME,0);
   n7.printStats();

   std::cout << "Case 8: Schedule Auto" << std::endl;
   ArrayFiller n8;
   n8.BadFillArrayConcurrently(AUTO,0);
   n8.printStats();

}

