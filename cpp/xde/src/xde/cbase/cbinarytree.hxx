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
 *   File: cbinarytree.hxx
 *
 * Author: $author$
 *   Date: 9/29/2017
 **********************************************************************
 */
#ifndef _XDE_CBASE_CBINARYTREE_HXX
#define _XDE_CBASE_CBINARYTREE_HXX

#include "xde/cbase/cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

class c_EXPORT_CLASS cBinaryTreeBranch;
/**
 **********************************************************************
 *  Class: cBinaryTreeBranchT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template
<class TLeaf,
 class TBranch,
 class TExtends = cBase>

class c_EXPORT_CLASS cBinaryTreeBranchT: public TExtends {
public:
    typedef TExtends cExtends;

    typedef TBranch tBranch;
    typedef TLeaf tLeaf;

    TBranch *m_tree, *m_leftBranch, *m_rightBranch;

    /**
     **********************************************************************
     * Constructor: cBinaryTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBinaryTreeBranchT
    (TBranch *tree = 0, TBranch *leftBranch = 0, TBranch *rightBranch = 0)
    : m_tree(tree), m_leftBranch(leftBranch), m_rightBranch(rightBranch) {
    }
    /**
     **********************************************************************
     * Destructor: ~cBinaryTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBinaryTreeBranchT() {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const TBranch& toBranch) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const TLeaf& toLeaf) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const TLeaf& toLeaf, int length) const = 0;
    /**
     **********************************************************************
     * Function: SetTree
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetTree(TBranch *tree) {
        return m_tree = tree;
    }
    /**
     **********************************************************************
     * Function: GetTree
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetTree() const {
        return m_tree;
    }
    /**
     **********************************************************************
     * Function: SetLeftBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetLeftBranch(TBranch *leftBranch) {
        return m_leftBranch = leftBranch;
    }
    /**
     **********************************************************************
     * Function: GetLeftBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetLeftBranch() const {
        return m_leftBranch;
    }
    /**
     **********************************************************************
     * Function: SetRightBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetRightBranch(TBranch *rightBranch) {
        return m_rightBranch = rightBranch;
    }
    /**
     **********************************************************************
     * Function: GetRightBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetRightBranch() const {
        return m_rightBranch;
    }
};

class c_EXPORT_CLASS cBinaryTree;
/**
 **********************************************************************
 *  Class: cBinaryTreeT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template
<class TLeaf,
 class TBranch,
 class TDerives,
 class TExtends = cBase>

class c_EXPORT_CLASS cBinaryTreeT: public TExtends {
public:
    typedef TExtends cExtends;

    TBranch *m_root;

    /**
     **********************************************************************
     * Constructor: cBinaryTreeT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBinaryTreeT(TBranch *root = 0): m_root(root) {
    }
    /**
     **********************************************************************
     * Destructor: ~cBinaryTreeT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBinaryTreeT() {
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Clear() {
        m_root=0;
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Insert(TBranch *branch) {
        TBranch *next, *tree;
        int unequal;

        if (!(next=GetRoot()))
            SetRoot(branch);

        else
        {
            do
            {
                tree=next;

                if ((unequal = branch->Compare(*tree)) < 0)
                {
                    if (!(next=tree->GetLeftBranch()))
                        tree->SetLeftBranch(branch);
                }
                else
                {
                    if (!(next=tree->GetRightBranch()))
                        tree->SetRightBranch(branch);
                }
            }
            while(next);

            branch->SetTree(tree);
        }
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Delete(TBranch *branch) {
        TBranch *next, *moved;

        if (!branch->GetLeftBranch() || !branch->GetRightBranch())
            moved = branch;

        else moved = GetNext(branch);

        if (!(next = moved->GetLeftBranch()))
            next = moved->GetRightBranch();

        if (next)
            next->SetTree(moved->GetTree());

        if (!moved->GetTree())
            SetRoot(next);

        else
        {
            if (moved == moved->GetTree()->GetLeftBranch())
                moved->GetTree()->SetLeftBranch(next);

            else moved->GetTree()->SetRightBranch(next);
        }

        if (moved != branch)
        {
            if ((next = moved->SetTree(branch->GetTree())))
                if (branch == next->GetRightBranch())
                    next->SetRightBranch(moved);
                else next->SetLeftBranch(moved);

            if ((next = moved->SetLeftBranch(branch->GetLeftBranch())))
                next->SetTree(moved);

            if ((next = moved->SetRightBranch(branch->GetRightBranch())))
                next->SetTree(moved);
        }
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *Find(unsigned &compares, const TLeaf &leaf) const {
        TBranch *branch;
        int unequal;
        unsigned count=0;

        if ((branch=GetRoot()))
        do
        {
            count++;

            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

            else break;
        }
        while(branch);

        compares = count;
        return branch;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *Find(const TLeaf &leaf) const {
        TBranch *branch;
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

            else break;
        }
        while(branch);

        return branch;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *Find(const TLeaf &leaf, int length) const {
        TBranch *branch;
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf, length)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

            else break;
        }
        while(branch);

        return branch;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetFirst() const {
        return GetFirstOf(GetRoot());
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetLast() const {
        return GetLastOf(GetRoot());
    }
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetNext(TBranch *branch) const {
        TBranch *tree;

        if ((tree=branch->GetRightBranch()))
            return GetFirstOf(tree);

        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetRightBranch())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetPrevious(TBranch *branch) const {
        TBranch *tree;

        if ((tree=branch->GetLeftBranch()))
            return GetLastOf(tree);

        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetLeftBranch())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }
    /**
     **********************************************************************
     * Function: SetRoot
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetRoot(TBranch *root) {
        return m_root=root;
    }
    /**
     **********************************************************************
     * Function: GetRoot
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetRoot() const {
        return m_root;
    }

protected:
    /**
     **********************************************************************
     * Function: GetFirstOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetFirstOf(TBranch *branch) const {
        TBranch *next;

        while ((next=branch->GetLeftBranch()))
            branch=next;
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLastOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetLastOf(TBranch *branch) const {
        TBranch *next;

        while ((next=branch->GetRightBranch()))
            branch=next;
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLeftOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetLeftOf(TBranch *branch) const {
        if (branch)
            return branch->GetLeftBranch();
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetRightOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetRightOf(TBranch *branch) const {
        if (branch)
            return branch->GetRightBranch();
        return 0;
    }
};

class c_EXPORT_CLASS cBalancedBinaryTreeBranch;
/**
 **********************************************************************
 *  Class: cBalancedBinaryTreeBranchT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template
<class TLeaf,
 class TDerives,
 class TBase = cBase,
 class TExtend = cBinaryTreeBranchT<TLeaf, TDerives, TBase>,
 class TExtends = TExtend>

class c_EXPORT_CLASS cBalancedBinaryTreeBranchT: public TExtends {
public:
    typedef TExtends cExtends;

    int m_depth;

    /**
     **********************************************************************
     * Constructor: cBalancedBinaryTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBalancedBinaryTreeBranchT
    (int depth = 1, TDerives *tree = 0,
     TDerives *leftBranch = 0, TDerives *rightBranch = 0)
    : cExtends(tree,leftBranch,rightBranch), m_depth(depth) {
    }
    /**
     **********************************************************************
     * Destructor: ~cBalancedBinaryTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBalancedBinaryTreeBranchT() {
    }
};

class c_EXPORT_CLASS cBalancedBinaryTree;
/**
 **********************************************************************
 *  Class: cBalancedBinaryTreeT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template
<class TLeaf,
 class TBranch,
 class TDerives,
 class TBase = cBase,
 class TExtend = cBinaryTreeT<TLeaf, TBranch, TDerives,TBase>,
 class TExtends = TExtend>

class c_EXPORT_CLASS cBalancedBinaryTreeT: public TExtends {
public:
    typedef TExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cBalancedBinaryTreeT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBalancedBinaryTreeT(TBranch *root=0): cExtends(root) {
    }
    /**
     **********************************************************************
     * Destructor: ~cBalancedBinaryTreeT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBalancedBinaryTreeT() {
    }

    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Insert an item into the tree and return the root.
     *
     **********************************************************************
     */
    TBranch *Insert(TBranch *branch) {
        branch->m_leftBranch=0;
        branch->m_rightBranch=0;
        return CTHIS m_root=Inserted(CTHIS m_root,branch);
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Delete an item from the tree and return the root.
     *
     **********************************************************************
     */
    TBranch *Delete(TBranch *branch) {
        return CTHIS m_root=Deleted(CTHIS m_root,branch);
    }

protected:
    /**
     **********************************************************************
     * Function: Inserted
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform recursive balanced insertion of an item into the
     * current subtree. Return the new root of the subtree.
     *
     **********************************************************************
     */
    TBranch *Inserted(TBranch *tree,TBranch *branch) {
        if (tree==0)
            return branch;

        if (branch!=0)
        if (branch->Compare(*tree)<0)
        {
            tree->m_leftBranch=Inserted(tree->m_leftBranch,branch);
            tree->m_leftBranch->m_tree=tree;
            if (Depth(tree->m_leftBranch)-Depth(tree->m_rightBranch)>1)
            {
                if (Depth(tree->m_leftBranch->m_rightBranch)
                    >Depth(tree->m_leftBranch->m_leftBranch))
                    tree->m_leftBranch=Left(tree->m_leftBranch);
                return Right(tree);
            }
            else tree->m_depth=tree->m_leftBranch->m_depth+1;
        }
        else
        {
            tree->m_rightBranch=Inserted(tree->m_rightBranch,branch);
            tree->m_rightBranch->m_tree=tree;
            if (Depth(tree->m_rightBranch)-Depth(tree->m_leftBranch)>1)
            {
                if (Depth(tree->m_rightBranch->m_leftBranch)
                    >Depth(tree->m_rightBranch->m_rightBranch))
                    tree->m_rightBranch=Right(tree->m_rightBranch);
                return Left(tree);
            }
            else tree->m_depth=tree->m_rightBranch->m_depth+1;
        }

        return tree;
    }
    /**
     **********************************************************************
     * Function: Deleted
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform recursive balanced deletion of an item from the
     * current subtree. Return the new root of the subtree.
     *
     **********************************************************************
     */
    TBranch *Deleted(TBranch *tree,TBranch *branch) {
        int c;

        if ((tree==0)||(branch==0))
            return tree;

        if ((c=branch->Compare(*tree))>0)
        {
            tree->m_rightBranch=Deleted(tree->m_rightBranch,branch);
            if (Depth(tree->m_leftBranch)-Depth(tree->m_rightBranch)>1)
            {
                if (Depth(tree->m_leftBranch->m_rightBranch)
                    >Depth(tree->m_leftBranch->m_leftBranch))
                    tree->m_leftBranch=Left(tree->m_leftBranch);
                tree=Right(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (c<0)
        {
            tree->m_leftBranch=Deleted(tree->m_leftBranch,branch);
            if (Depth(tree->m_rightBranch)-Depth(tree->m_leftBranch)>1)
            {
                if (Depth(tree->m_rightBranch->m_leftBranch)
                    >Depth(tree->m_rightBranch->m_rightBranch))
                    tree->m_rightBranch=Right(tree->m_rightBranch);
                tree=Left(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (branch->m_depth>1)
        {
            if (Depth(branch->m_rightBranch)>Depth(branch->m_leftBranch))
                tree=Least(&branch->m_rightBranch);
            else tree=Greatest(&branch->m_leftBranch);
            tree->m_depth=NewDepth(branch);
            if ((tree->m_leftBranch=branch->m_leftBranch)!=0)
                tree->m_leftBranch->m_tree=tree;
            if ((tree->m_rightBranch=branch->m_rightBranch)!=0)
                tree->m_rightBranch->m_tree=tree;
        }
        else tree=0;

        return tree;
    }
    /**
     **********************************************************************
     * Function: Least
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Recusively raise the least item in the subtree to
     * the top of the tree.
     *
     **********************************************************************
     */
    TBranch *Least(TBranch **tree) {
        TBranch *t;

        if ((*tree)->m_leftBranch!=0)
        {
            t=Least(&(*tree)->m_leftBranch);
            if (Depth((*tree)->m_rightBranch)-Depth((*tree)->m_leftBranch)>1)
            {
                if (Depth((*tree)->m_rightBranch->m_leftBranch)
                    >Depth((*tree)->m_rightBranch->m_rightBranch))
                    (*tree)->m_rightBranch=Right((*tree)->m_rightBranch);
                *tree=Left(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_rightBranch!=0)
        {
            t=*tree;
            *tree=t->m_rightBranch;
        }
        else
        {
            t=*tree;
            *tree=0;
        }

        return t;
    }
    /**
     **********************************************************************
     * Function: Greatest
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Recusively raise the greatest item in the subtree to
     * the top of the tree.
     *
     **********************************************************************
     */
    TBranch *Greatest(TBranch **tree) {
        TBranch *t;

        if ((*tree)->m_rightBranch!=0)
        {
            t=Greatest(&(*tree)->m_rightBranch);
            if (Depth((*tree)->m_leftBranch)-Depth((*tree)->m_rightBranch)>1)
            {
                if (Depth((*tree)->m_leftBranch->m_rightBranch)
                    >Depth((*tree)->m_leftBranch->m_leftBranch))
                    (*tree)->m_leftBranch=Left((*tree)->m_leftBranch);
                *tree=Right(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_leftBranch!=0)
        {
            t=*tree;
            *tree=t->m_leftBranch;
        }
        else
        {
            t=*tree;
            *tree=0;
        }

        return t;
    }
    /**
     **********************************************************************
     * Function: Left
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform rotation left to balance the tree.
     *
     **********************************************************************
     */
    TBranch *Left(TBranch *tree) {
        TBranch *rightBranch;

        if (tree)
        if ((rightBranch=tree->m_rightBranch))
        {
            if ((tree->m_rightBranch=rightBranch->m_leftBranch))
                tree->m_rightBranch->m_tree=tree;

            tree->m_depth=Depth(tree->m_leftBranch)+1;

            if (Depth(tree->m_rightBranch)>=tree->m_depth)
                tree->m_depth=tree->m_rightBranch->m_depth+1;

            rightBranch->m_depth=tree->m_depth+1;
            rightBranch->m_leftBranch=tree;
            rightBranch->m_tree=tree->m_tree;
            tree->m_tree=rightBranch;

            return rightBranch;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: Right
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform rotation right to balance the tree.
     *
     **********************************************************************
     */
    TBranch *Right(TBranch *tree) {
        TBranch *leftBranch;

        if (tree)
        if ((leftBranch=tree->m_leftBranch))
        {
            if ((tree->m_leftBranch=leftBranch->m_rightBranch))
                tree->m_leftBranch->m_tree=tree;

            tree->m_depth=Depth(tree->m_rightBranch)+1;

            if (Depth(tree->m_leftBranch)>=tree->m_depth)
                tree->m_depth=tree->m_leftBranch->m_depth+1;

            leftBranch->m_depth=tree->m_depth+1;
            leftBranch->m_rightBranch=tree;
            leftBranch->m_tree=tree->m_tree;
            tree->m_tree=leftBranch;

            return leftBranch;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: NewDepth
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Return the new depth of tree.
     *
     **********************************************************************
     */
    int NewDepth(TBranch *tree) {
        int ld,gd;

        if (tree!=0)
        if ((ld=Depth(tree->m_leftBranch))
            >(gd=Depth(tree->m_rightBranch)))
            return ld+1;
        else return gd+1;

        return 0;
    }
    /**
     **********************************************************************
     * Function: Depth
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    int Depth(TBranch *tree) const {
        if (tree)
        if (tree->m_depth>0)
            return tree->m_depth;
        else return 1;

        return 0;
    }
};

/**
 **********************************************************************
 *  Class: cBalancedBinaryTreeBranch
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
typedef cBalancedBinaryTreeBranchT
<CHAR, cBalancedBinaryTreeBranch, cBase> cBalancedBinaryTreeBranchExtends;
class c_EXPORT_CLASS cBalancedBinaryTreeBranch: public cBalancedBinaryTreeBranchExtends {
public:
    typedef cBalancedBinaryTreeBranchExtends cExtends;
    CHAR m_leaf;
    /**
     **********************************************************************
     * Constructor: cBalancedBinaryTreeBranch
     *
     *      Author: $author$
     *        Date: 3/29/2008
     **********************************************************************
     */
    cBalancedBinaryTreeBranch(CHAR leaf): m_leaf(leaf) {}
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const tBranch& toBranch) const {
        const tLeaf& toLeaf = toBranch.GetLeaf();
        int unequal = Compare(toLeaf);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const tLeaf& toLeaf) const {
        const tLeaf& leaf = GetLeaf();
        int unequal = (leaf > toLeaf)?(1):((leaf < toLeaf)?-1:0);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const tLeaf& toLeaf, int length) const {
        const tLeaf& leaf = GetLeaf();
        int unequal = (leaf > toLeaf)?(1):((leaf < toLeaf)?-1:0);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetLeaf
     *
     *   Author: $author$
     *     Date: 3/29/2008
     **********************************************************************
     */
    virtual CHAR& GetLeaf() const {
        return (CHAR&)(m_leaf);
    }
};
/**
 **********************************************************************
 *  Class: cBalancedBinaryTree
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
typedef cBalancedBinaryTreeT
<CHAR,cBalancedBinaryTreeBranch,cBase> cBalancedBinaryTreeExtend;
class c_EXPORT_CLASS cBalancedBinaryTree: public cBalancedBinaryTreeExtend {
public:
    typedef cBalancedBinaryTreeExtend cExtends;
    /**
     **********************************************************************
     * Constructor: cBalancedBinaryTree
     *
     *      Author: $author$
     *        Date: 3/29/2008
     **********************************************************************
     */
    cBalancedBinaryTree() {}
    /**
     **********************************************************************
     * Destructor: cBalancedBinaryTree
     *
     *     Author: $author$
     *       Date: 3/29/2008
     **********************************************************************
     */
    virtual ~cBalancedBinaryTree() {}
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _XDE_CBASE_CBINARYTREE_HXX */
