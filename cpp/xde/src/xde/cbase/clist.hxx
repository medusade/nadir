/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: clist.hxx
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
#ifndef _XDE_CBASE_CLIST_HXX
#define _XDE_CBASE_CLIST_HXX

#include "xde/cbase/cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cListItem;
/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 2/1/2007
 **********************************************************************
 */
template
<class TDerives,
 class TExtends = cBase>

class c_EXPORT_CLASS cListItemT: public TExtends {
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    TDerives *m_prevItem, *m_nextItem;

    /**
     **********************************************************************
     * Constructor: cListItemT
     *
     *      Author: $author$
     *        Date: 2/1/2007
     **********************************************************************
     */
    cListItemT(TDerives *prevItem = 0, TDerives *nextItem = 0)
    :m_prevItem(prevItem), m_nextItem(nextItem) {
    }
    /**
     **********************************************************************
     *  Destructor: ~cListItemT
     *
     *      Author: $author$
     *        Date: 2/1/2007
     **********************************************************************
     */
    virtual ~cListItemT() {
    }
    /**
     **********************************************************************
     * Function: GetPrevItem
     *
     *   Author: $author$
     *     Date: 2/1/2007
     **********************************************************************
     */
    TDerives *GetPrevItem() const {
        return m_prevItem;
    }
    /**
     **********************************************************************
     * Function: GetNextItem
     *
     *   Author: $author$
     *     Date: 2/1/2007
     **********************************************************************
     */
    TDerives *GetNextItem() const {
        return m_nextItem;
    }
};

/**
 **********************************************************************
 *  Class: cListBaseT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem,
 class TExtends = cBase>

class c_EXPORT_CLASS cListBaseT: public TExtends {
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cListBaseT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    cListBaseT(TItem* firstItem = 0, TItem* lastItem = 0)
    : m_firstItem(firstItem), m_lastItem(lastItem) {
    }
    /**
     **********************************************************************
     *  Destructor: ~cListBaseT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    virtual ~cListBaseT() {
    }

    /**
     **********************************************************************
     **********************************************************************
     */
    virtual TItem*& firstItem() const {
        return (TItem*&)m_firstItem;
    }
    virtual TItem*& lastItem() const {
        return (TItem*&)m_lastItem;
    }
    /**
     **********************************************************************
     **********************************************************************
     */
    TItem *m_firstItem, *m_lastItem;
};

/**
 **********************************************************************
 *  Class: cListT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem,
 class TBase = cBase,
 class TList = cListBaseT<TItem, TBase>,
 class TExtends = TList>

class c_EXPORT_CLASS cListT: public TExtends {
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    cListT(TItem* firstItem, TItem* lastItem) {
        this->firstItem() = firstItem;
        this->lastItem() = lastItem;
    }
    cListT() {
    }
    /**
     **********************************************************************
     *  Destructor: ~cListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    virtual ~cListT() {
    }

    /**
     **********************************************************************
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: ClearItems
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    void ClearItems() {
        this->firstItem() = this->lastItem() = 0;
    }
    /**
     **********************************************************************
     * Function: AddItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    void AddItem(TItem& item) {
        item.m_nextItem = 0;

        if ((item.m_prevItem = this->lastItem()))
            this->lastItem()->m_nextItem = &item;
        else this->firstItem() = &item;

        this->lastItem() = &item;
    }
    /**
     **********************************************************************
     * Function: PushItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    void PushItem(TItem& item) {
        item.m_prevItem = 0;

        if ((item.m_nextItem = this->firstItem()))
            this->firstItem()->m_prevItem = &item;
        else this->lastItem() = &item;

        this->firstItem() = &item;
    }
    /**
     **********************************************************************
     * Function: InsertBeforeItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    void InsertBeforeItem(TItem& otherItem, TItem& item) {
        if ((item.m_prevItem = otherItem.m_prevItem))
            otherItem.m_prevItem->m_nextItem = &item;
        else this->firstItem() = &item;

        item.m_nextItem = &otherItem;
        otherItem.m_prevItem = &item;
    }
    /**
     **********************************************************************
     * Function: InsertAfterItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    void InsertAfterItem(TItem& otherItem, TItem& item) {
        if ((item.m_nextItem = otherItem.m_nextItem))
            otherItem.m_nextItem->m_prevItem = &item;
        else this->lastItem() = &item;

        item.m_prevItem = &otherItem;
        otherItem.m_nextItem = &item;
    }
    /**
     **********************************************************************
     * Function: DeleteItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    void DeleteItem(TItem& item) {
        if (item.m_nextItem)
            item.m_nextItem->m_prevItem = item.m_prevItem;
        else this->lastItem() = item.m_prevItem;

        if (item.m_prevItem)
            item.m_prevItem->m_nextItem = item.m_nextItem;
        else this->firstItem() = item.m_nextItem;

        item.m_nextItem = 0;
        item.m_prevItem = 0;
    }

    /**
     **********************************************************************
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: AddItems
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    void AddItems
    (TItem& firstItem, TItem& lastItem) {
        lastItem.m_nextItem = 0;

        if ((firstItem.m_prevItem = this->lastItem()) != 0)
            this->lastItem()->m_nextItem = &firstItem;
        else this->firstItem() = &firstItem;

        this->lastItem() = &lastItem;
    }
    /**
     **********************************************************************
     * Function: PushItems
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    void PushItems
    (TItem& firstItem, TItem& lastItem) {
        firstItem.m_prevItem = 0;

        if ((lastItem.m_nextItem = this->firstItem()) != 0)
            this->firstItem()->m_prevItem = &lastItem;
        else this->lastItem() = &lastItem;

        this->firstItem() = &firstItem;
    }
    /**
     **********************************************************************
     * Function: InsertItemsBefore
     *
     *   Author: $author$
     *     Date: 11/29/2007
     **********************************************************************
     */
    void InsertItemsBefore
    (TItem& otherItem, TItem& firstItem, TItem& lastItem) {
        if ((firstItem.m_prevItem = otherItem.m_prevItem) != 0)
            otherItem.m_prevItem->m_nextItem = &firstItem;
        else this->firstItem() = &firstItem;

        lastItem.m_nextItem = &otherItem;
        otherItem.m_prevItem = &lastItem;
    }
    /**
     **********************************************************************
     * Function: InsertItemsAfter
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    void InsertItemsAfter
    (TItem& otherItem, TItem& firstItem, TItem& lastItem) {
        if ((lastItem.m_nextItem = otherItem.m_nextItem) != 0)
            otherItem.m_nextItem->m_prevItem = &lastItem;
        else this->lastItem() = &lastItem;

        firstItem.m_prevItem = &otherItem;
        otherItem.m_nextItem = &firstItem;
    }
    /**
     **********************************************************************
     * Function: DeleteItems
     *
     *   Author: $author$
     *     Date: 11/29/2008
     **********************************************************************
     */
    void DeleteItems
    (TItem& firstItem, TItem& lastItem) {
        if (lastItem.m_nextItem)
            lastItem.m_nextItem->m_prevItem = firstItem.m_prevItem;
        else this->lastItem() = firstItem.m_prevItem;

        if (firstItem.m_prevItem)
            firstItem.m_prevItem->m_nextItem = lastItem.m_nextItem;
        else this->firstItem() = lastItem.m_nextItem;

        lastItem.m_nextItem = 0;
        firstItem.m_prevItem = 0;
    }

    /**
     **********************************************************************
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: PopItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    TItem* PopItem() {
        TItem* item = 0;

        if ((item = this->firstItem()))
        {
            TItem* nextItem;

            if ((nextItem = item->m_nextItem))
                nextItem->m_prevItem = 0;
            else this->lastItem() = 0;

            this->firstItem() = nextItem;
            item->m_nextItem = 0;
            item->m_prevItem = 0;
        }
        return item;
    }
    /**
     **********************************************************************
     * Function: PullItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    TItem* PullItem() {
        TItem* item = 0;

        if ((item = this->lastItem()))
        {
            TItem* prevItem;

            if ((prevItem = item->m_prevItem))
                prevItem->m_nextItem = 0;
            else this->firstItem() = 0;

            this->lastItem() = prevItem;
            item->m_nextItem = 0;
            item->m_prevItem = 0;
        }
        return item;
    }

    /**
     **********************************************************************
     **********************************************************************
     */

    /**
     **********************************************************************
     * Function: GetFirstItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    TItem* GetFirstItem() const {
        TItem* item = this->firstItem();
        return item;
    }
    /**
     **********************************************************************
     * Function: GetLastItem
     *
     *   Author: $author$
     *     Date: 1/26/2007
     **********************************************************************
     */
    TItem* GetLastItem() const {
        TItem* item = this->lastItem();
        return item;
    }
};

/**
 **********************************************************************
 *  Class: cStaticListBaseT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem,
 class TBase = cBase,
 class TListBase = cListBaseT<TItem, TBase>,
 class TExtends = TListBase>

class c_EXPORT_CLASS cStaticListBaseT: public TExtends {
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cStaticListBaseT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    cStaticListBaseT() {
    }
    /**
     **********************************************************************
     *  Destructor: ~cStaticListBaseT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    virtual ~cStaticListBaseT() {
    }

    /**
     **********************************************************************
     **********************************************************************
     */
    virtual TItem*& firstItem() const {
        static TItem* firstItem = 0;
        return firstItem;
    }
    virtual TItem*& lastItem() const {
        static TItem* lastItem = 0;
        return lastItem;
    }
};

class c_EXPORT_CLASS cStaticListItem;
class c_EXPORT_CLASS cStaticList;
/**
 **********************************************************************
 *  Class: cStaticListT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem,
 class TBase = cBase,
 class TListBase = cStaticListBaseT<TItem, TBase>,
 class TList = cListT<TItem, TListBase>,
 class TExtends = TList>

class c_EXPORT_CLASS cStaticListT: public TExtends {
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cStaticListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    cStaticListT() {
    }
    /**
     **********************************************************************
     *  Destructor: ~cStaticListT
     *
     *      Author: $author$
     *        Date: 1/26/2007
     **********************************************************************
     */
    virtual ~cStaticListT() {
    }
};
/**
 **********************************************************************
 *  Class: cStaticList/cStaticListItem
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
class c_EXPORT_CLASS cStaticList: public cStaticListT<cStaticListItem> {};
class c_EXPORT_CLASS cStaticListItem: public cListItemT<cStaticListItem> {
public:
    cStaticList& m_list;
    cStaticListItem(cStaticList& list): m_list(list) {
        m_list.AddItem(*this);
    }
    virtual ~cStaticListItem() {
        m_list.DeleteItem(*this);
    }
};

/**
 **********************************************************************
 *  Class: cDynamicListItemT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template
<class TDerives,
 class TBase = cBase,
 class TListItem = cListItemT<TDerives, TBase>,
 class TExtends = TListItem>

class c_EXPORT_CLASS cDynamicListItemT: public TExtends {
public:
    typedef TExtends cExtends;

    bool m_is_static, m_is_persistant;

    /**
     **********************************************************************
     * Constructor: cDynamicListItemT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cDynamicListItemT
    (bool is_static = false, bool is_persistant = false,
     TDerives *previous = 0, TDerives *next = 0)
    : cExtends(previous, next),
      m_is_static(is_static), m_is_persistant(is_persistant) {
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool SetIsStatic(bool is_static = true) {
        m_is_static = is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool GetIsStatic() const {
        return m_is_static;
    }

    /**
     **********************************************************************
     * Function: SetIsPersistant
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool SetIsPersistant(bool is_persistant = true) {
        m_is_persistant = is_persistant;
        return m_is_persistant;
    }
    /**
     **********************************************************************
     * Function: GetIsPersistant
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    bool GetIsPersistant() const {
        return m_is_persistant;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicListT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template
<class TItem,
 class TBase = cBase,
 class TList = cListT<TItem, TBase>,
 class TExtends = TList>

class c_EXPORT_CLASS cDynamicListT: public TExtends {
public:
    typedef TExtends cExtends;

    bool m_is_static;

    /**
     **********************************************************************
     * Constructor: cDynamicListT
     *
     *      Author: $author$
     *        Date: 7/13/2003
     **********************************************************************
     */
    cDynamicListT
    (bool is_static = false,
     TItem *first = 0,TItem *last = 0)
    : cExtends(first,last), m_is_static(is_static) {
    }
    /**
     **********************************************************************
     * Destructor: ~cDynamicListT
     *
     *     Author: $author$
     *       Date: 7/13/2003
     **********************************************************************
     */
    virtual ~cDynamicListT() {
        Destruct();
    }
    /**
     **********************************************************************
     * Function: Destruct
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual void Destruct() {
        eError error;

        if ((error = Clear()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError Clear() {
        eError error;
        TItem *item,*previous;

        if (m_is_static)
            CTHIS m_firstItem = CTHIS m_lastItem = 0;

        else for (item = CTHIS m_lastItem; item; item = previous)
        {
            previous = item->m_prevItem;

            if (!item->m_is_persistant)
            {
                CTHIS DeleteItem(*item);

                if (!item->m_is_static)
                if ((error = FreeItem(*item)))
                    return e_ERROR_FREE;
            }
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: FreeItem
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    virtual eError FreeItem(TItem& item) {
        delete &item;
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: SetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool SetIsStatic(bool is_static = true) {
        m_is_static = is_static;
        return m_is_static;
    }
    /**
     **********************************************************************
     * Function: GetIsStatic
     *
     *   Author: $author$
     *     Date: 7/13/2003
     **********************************************************************
     */
    inline bool GetIsStatic() const {
        return m_is_static;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CBASE_CLIST_HXX */
