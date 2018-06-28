#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          necessary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int flag =0;///si es 0 hay espacio, si no, no gg

    if(this!=NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            if(resizeUp(this)!=0)
            {
                flag=1;
            }
        }

        if(!flag)
        {
            this->pElements[this->size]=pElement; ///pasa elelemento nuevo al array
            this->size++; ///suma el tamaño para el proximo index (y se mantiene vacio)
            return 0;
        }  ///SIZE -> lugar del elemento libre, nunca va a haber nada, siempre es el "siguiente" al que estemos manejando
        ///reservedSize es el tamañototal reservado lol
        ///if reservedsize=size no hay lugar
    }
    return -1;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    if(this!=NULL)
    {
        //dentro de THIS solo tpcamos size reserved y pelements
        this->size=0;
        free(this->pElements);
        return 0;
    }
    return -1;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer] *****
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index >= 0 && index < al_len(this))
    {
        ///returnAux = this->pElements[index]; esto es array
        returnAux = *(this->pElements+index); ///porque es puntero (aritmetica de ptrs)
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int i = 0;
    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            if(pElement==al_get(this,i))
            {
                return 1;
            }
        }
        return 0;
    }
    return -1;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    if(this!=NULL && index >= 0 && index <= al_len(this) && pElement != NULL)
    {

        if(index==al_len(this))
        {
            al_add(this,pElement);
        }
        if(index<al_len(this))
        {
            *(this->pElements+index) = pElement;
        }
        return 0;

    }
    return -1;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    if(this!=NULL && index >= 0 && index < al_len(this)) ///menor porque len no existe (todavia)
    {
        contract(this,index);
        this->size--;
        return 0;
    }

    return -1;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    if(this!=NULL)
    {
        this->size=0;
        this->reservedSize=AL_INITIAL_VALUE;
        return 0;
    }
    return -1;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;
    if(this!=NULL)
    {
        returnAux=al_newArrayList();
        for(i=0; i<=this->size; i++)
        {
            al_add(returnAux,this->pElements[i]);
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    if(this!=NULL && index >= 0 && index <= al_len(this) && pElement != NULL)
    {
        if(this->size==index)///si es igual a size, add
        {
            al_add(this,pElement);
            return 0;
        }
        else if(expand(this,index)==0) ///si es menor, set
        {
            al_set(this,index,pElement);
            return 0;
        }

    }
    return -1;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int i;
    if(this!=NULL && pElement != NULL)
    {
        for(i=0; i<= this->size ; i++)
        {
            if(*(this->pElements+i)==pElement)
            {
                return i;
            }
        }
    }
    return -1;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    if(this!=NULL)
    {
        if(this->size==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return -1;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index < this->size && index >= 0)
    {
        returnAux = *(this->pElements+index);
        al_remove(this,index);
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;
    int i;
    if(this!=NULL && from < to && from >=0)
    {
        returnAux=al_newArrayList();
        if(returnAux!=NULL)
        {
            for(i=from; i<to; i++)
            {
                al_add(returnAux,*(this->pElements+i));
            }
        }
    }
    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int i;
    if(this!=NULL && this2!=NULL)
    {
        if(this->size!=this->size)
        {
            return 0;
        }
        else
        {
            for(i=0; i<this2->size; i++)
            {
                if(al_contains(this,*(this2->pElements+i))!=1)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    return -1;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    void* aux;
    void* pElement1;
    void* pElement2;
    int i, j;
    if(this!=NULL && pFunc!=NULL && (order == 0 || order == 1))
    {
        for(i=0; i<this->size-1; i++)
        {
            for(j=i+1; j<this->size; j++)
            {
                pElement1 = al_get(this,i);
                pElement2 = al_get(this,j);
                if(order)
                {
                    if((*pFunc)(pElement1,pElement2))
                    {
                        aux=*(this->pElements+i);
                        *(this->pElements+i)=*(this->pElements+j);
                        *(this->pElements+j)=aux;
                        ///asi swappeo los elementos del array
                    }
                }
                else
                {
                    if((*pFunc)(pElement1,pElement2)==-1)
                    {
                        aux=*(this->pElements+i);
                        *(this->pElements+i)=*(this->pElements+j);
                        *(this->pElements+j)=aux;
                    }
                }
            }
        }
        return 0;
    }


    return -1;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this) ///realloc para mas elementos
{
    void** aux;
    aux=(void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize+AL_INCREMENT));
    if(aux!=NULL)
    {
        this->pElements=aux;
        this->reservedSize=this->reservedSize+AL_INCREMENT;
        return 0;
    }
    return -1;

}
///mueve otros al costado para ponr algo en el medio "hacia adelante" a partir del indice donde ponemos eso
/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int i;
    if(this!=NULL&&index<al_len(this)&&index>=0)
    {
        for(i=al_len(this); i>=index; i--)
        {
            al_add(this,*(this->pElements+i+1));
        }
        return 0;
    }
    return -1;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
///no se peude usar free, porque si tiene esa posi usadaen otra estructura, se pierde esa estructura
///se desplaza todo 1 para atras a partir del indice (pisandolos)

int contract(ArrayList* this,int index)
{
    int i;
    if(this!=NULL && this->pElements!=NULL)
    {
        for(i=index; i<this->size; i++)
        {
            *(this->pElements+i)=*(this->pElements+(i+1));
        }
        return 0;
    }
    return -1;
}

