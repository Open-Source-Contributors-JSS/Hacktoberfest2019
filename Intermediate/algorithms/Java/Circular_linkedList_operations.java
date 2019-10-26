class circular
{ 

static class Node 
{ 
	int data; 
	Node next; 
}; 
   static Node last;

static Node addToEmpty(int data) 
{ 
	// This function is only for empty list 
	if (last != null) 
	return last; 

	// Creating a node dynamically. 
	Node temp = new Node(); 

	// Assigning the data. 
	temp.data = data; 
	last = temp; 

	// Creating the link. 
	last.next = last; 

	return last; 
} 

static Node addBegin(int data) 
{ 
	if (last == null) 
		return addToEmpty(data); 

	Node temp = new Node(); 

	temp.data = data; 
	temp.next = last.next; 
	last.next = temp; 

	return last; 
} 

static Node addEnd(int data) 
{ 
	if (last == null) 
		return addToEmpty(data); 
	
	Node temp = new Node(); 

	temp.data = data; 
	temp.next = last.next; 
	last.next = temp; 
	last = temp; 

	return last; 
} 

static Node addAfter(int data, int item) 
{ 
	if (last == null) 
		return null; 

	Node temp, p; 
	p = last.next; 
	do
	{ 
		if (p.data == item) 
		{ 
			temp = new Node(); 
			temp.data = data; 
			temp.next = p.next; 
			p.next = temp; 

			if (p == last) 
				last = temp; 
			return last; 
		} 
		p = p.next; 
		} while(p != last.next); 

		System.out.println(item + " not present in the list."); 
		return last; 

	} 

static void traverse(Node last) 
{ 
	Node p; 

	// If list is empty, return. 
	if (last == null) 
	{ 
		System.out.println("List is empty."); 
		return; 
	} 

	// Pointing to first Node of the list. 
	p = last.next; 

	// Traversing the list. 
	do
	{ 
		System.out.print(p.data + " "); 
		p = p.next; 

	} 
	while(p != last.next); 

} 

   static void delAtLast()
   {
	  Node p =last.next;
	   Node t = last;
	   
	   if (last == null)
	   {
		   System.out.print("Underflow");
		   
	   }
	   
	   else if (last.next == last)

	   {
		   
		   last=null;
	   }	

		else

		{
			while (p.next != last)
			{			
				p=p.next;				
			}
			
			p.next = last.next;
			last = p;
		}
		t=null;
	
   }
 
   static void delAtBeg()
   {
 
	   Node p =last.next;
	 // Node temp = last;
		Node t =last;
	 // last = last.next.next;
	 t.next = p.next;
	   
	   System.out.println(p.data);
	   p = null; 
	   
 
	    }
   
   static void reverse(Node last)
   {
	  
	  
	  Node prev = last;
	   Node current =last.next;
	  Node next1 = null ;
	  Node first = last.next;
	  
	  if ( last == null || last.next == last )
			return ;
	  
	  
	  last.next = null;
	  
	  while(current != null)
	  {
		  
		  next1 = current.next;
		  current.next = prev;
		  prev = current;
		  current = next1;
	  }
	 
	last = first;
   }

// Main
public static void main(String[] args) 
{ 
	
	 addToEmpty(6); 
	last = addBegin(4); 
	last = addBegin(2); 
	last = addEnd(8); 
	last = addEnd(12); 
	last = addAfter(10, 8); 
	delAtLast();
	delAtLast();
	 delAtBeg();
      delAtBeg();
	   delAtBeg();
	 // traverse(last); 
	
	// reverse(last);
	 traverse(last);
} 
}