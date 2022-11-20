// Assignment 3 - Implementing COW mechanism on xv6 fork().
// a map of the implementation:

/* 
    1. Modify uvmcopy() to map the parent's physical pages into the child, instead of allocating new pages.

       1.1. Mark the page as read-only of both child and parent - PTE_W = 0 (DONE)
       1.2. Add PTE_COW bit in the PTEs. (DONE)
       1.3. Mark each page as COW.



    2. Modify usertrap() to recognize page faults, by calling the function "pagefaulthandler()" from the file :(????). 

       The new function must work in this way:
        2.1. Allocate a new page with kalloc().
        2.2. Copy the old page to a new page, for the process that caused the page fault.
        2.3. Mark the new copied page as writable.
        2.3. Install the new page in the PTE with PTE_W set.
         * The process thet caused the page fault must be blocked after.
         * The releveant r_cause() = 15


    3. By deleting the last PTE of any physical page, it must be freed, in order to avoid memory leaks.
       for that, we need a "reference count", to count the number of user page tables that refer to that page.
       the counter is an array of "entries of each phisical page", synchronized by CAS.

        3.1. Set a page's reference count to '1' when kalloc() allocates it. 
        3.2. Increment a page's reference count when fork() causes a child to share the page.
        3.3. Decrement a page's count each time any process drops the page from its page table.
        3.4. kfree() should only place a page back on the free list if its reference count is zero.
        * The number of the physical pages that can be dynamically alloacted can be calculated using the following formula: (????)
            #define NUM_PYS_PAGES ((PHYSTOP-KERNBASE) / PGSIZE)


*/