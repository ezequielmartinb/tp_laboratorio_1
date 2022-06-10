/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);// CONSTRUCTOR. CREA LA LISTA EN EL HEAP
int ll_len(LinkedList* this);//CUENTA LA CANTIDAD DE ELEMENTOS QUE TENGO DENTRO DE LA LISTA
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//AGREGA ELEMENTOS A LA LISTA
void* ll_get(LinkedList* this, int index);//DEVUELVE UN DATO DENTRO DE LA LISTA
int ll_set(LinkedList* this, int index,void* pElement);//REEMPLAZA UN ELEMENTO CON OTRO
int ll_remove(LinkedList* this,int index);//REMUEVE UN ELEMENTO DEL INDICE ESPECIFICADO
int ll_clear(LinkedList* this);//LIMPIA TODA LA LISTA, SIN BORRAR EL LINKED LIST
int ll_deleteLinkedList(LinkedList* this);//BORRAR EL LINKED LISTA. SERIA EL "DESTRUCTOR"
int ll_indexOf(LinkedList* this, void* pElement);//BUSCAR EL INDICE DE UN ELEMENTO ESPECIFICO
int ll_isEmpty(LinkedList* this);//INDICA SI EL LINKED LIST ESTA VACIO O NO
int ll_push(LinkedList* this, int index, void* pElement);//AGREGA UN ELEMENTO EN EL INDICE ESPECIFICADO
void* ll_pop(LinkedList* this,int index);//DEVUELVE EL ELEMENTO QUE SACÓ DE LA LISTA
int ll_contains(LinkedList* this, void* pElement);//SI EXISTE UN ELEMENTO X DENTRO DE LA LISTA
int ll_containsAll(LinkedList* this,LinkedList* this2);//VERIFICA SI UNA LISTA ESTA DENTRO DE OTRA LISTA
LinkedList* ll_subList(LinkedList* this,int from,int to);//TE HACE UNA LISTA DESDE UN INDICE HASTA EL OTRO INDICE
LinkedList* ll_clone(LinkedList* this);//CLONA TODA UNA LISTA (LLAMA A SUBLIST Y VA DESDE EL PRIMER INDICE HASTA EL ULTIMO)
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ORDENA LA LISTA
