/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *Bu class kitaptan referans olarak alinmistir
 * Tum fonksiyonlar etkin olarak birakilmistir
 * Recursive fonksiyonunda degisikler yapilabilir
 * @author macboookair
 */
public class RecursiveList < E > {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        
    }
    /** The list head */
  private Node < E > head;

  /** A Node is the building block for a single-linked list. */
  private static class Node < E > {
    // Data Fields
    /** The reference to the data. */
    private E data;

    /** The reference to the next node. */
    private Node next;

    // Constructors
    /** Creates a new node with a null next field.
        @param dataItem The data stored
     */
    private Node(E dataItem) {
      data = dataItem;
      next = null;
    }

    /** Creates a new node that references another node.
        @param dataItem The data stored
        @param nodeRef The node referenced by new node
     */
    private Node(E dataItem, Node < E > nodeRef) {
      data = dataItem;
      next = nodeRef;
    }
  } //end class Node

  /** Finds the size of a list.
       @param head The head of the current list
       @RETURN THE SIZE OF THE CURRENT LIST
   */
  private int size(Node < E > head) {
    if (head == null)
      return 0;
    else
      return 1 + size(head.next);
  }

  /** Wrapper method for finding the size of a list.
      @return The size of the list
   */
  public int size() {
    return size(head);
  }

  /** Returns the string representation of a list.
      @param head The head of the current list
      @return The state of the current list
   */
  private String toString(Node < E > head) {
    if (head == null)
      return "";
    else
      return head.data + " " + toString(head.next);
  }

  /** Wrapper method for returning the string representation of a list.
      @return The string representation of the list
   */
  public String toString() {
    return toString(head);
  }

  /** Replaces all occurrences of oldObj with newObj.
      post: Each occurrence of oldObj has been replaced by newObj.
      @param head The head of the current list
      @param oldObj The object being removed
      @param newObj The object being inserted
   */
  private void replace(Node < E > head, E oldObj, E newObj) {
    if (head != null) {
      if (oldObj.equals(head.data))
        head.data = newObj;
      replace(head.next, oldObj, newObj);
    }
  }

  /*  Wrapper method for replacing oldObj with newObj.
      post: Each occurrence of oldObj has been replaced by newObj.
      @param oldObj The object being removed
      @param newObj The object being inserted
   */
  public void replace(E oldObj, E newObj) {
    replace(head, oldObj, newObj);
  }

  /** Adds a new node to the end of a list.
      @param head The head of the current list
      @param data The data for the new node
   */
  private void add(Node < E > head, E data) {
    // If the list has just one element, add to it.
    if (head.next == null)
      head.next = new Node < E > (data);
    else
      add(head.next, data); // Add to rest of list.
  }

  /** Wrapper method for adding a new node to the end of a list.
      @param data The data for the new node
   */
  public void add(E data) {
    if (head == null)
      head = new Node < E > (data); // List has 1 node.
    else
      add(head, data);
  }

  /** Removes a node from a list.
      post: Occurrences of outData is removed.
      @param head The head of the current list
      @param pred The predecessor of the list head
      @param outData The data to be removed
      @return true if the item is removed
              and false otherwise
   */
  private boolean remove(Node < E > head, Node < E > pred, E outData) {
    boolean flag;
    // System.out.println("a");
    if (head == null) // Base case ñ empty list.
      return false;
    
    if(pred==null && head.data.equals(outData))
    {
        pred.next=head.next;
        head.next=head.next.next;
        flag=false;
        
    }
    
    if (head.data.equals(outData)) 
    { // 2nd base case.
        //System.out.println("a");
      pred.next = head.next; // Remove head.
      //if(head.next.next.data.equals(outData))
      //pred.next=head.next.next;
      flag=false;
      return false;
    }
    /*
    if(head.data.equals(outData) && head.next.data.equals(outData))
    {
        pred.next=head.next.next;
        flag=false;
    }
    */
    
    else if(head.next ==null)
    {
          flag=true;
          return false;
    }
    /*else if(flag==true)
    {
        //pred.next=head.next;
        //pred.next=head.next.next;
        return true;
    }
          */
    else
    {
      return remove(head.next, head, outData);
    }
  }

  /** Wrapper method for removing a node (in LinkedListRec).
      post: The first occurrence of outData is removed.
      @param outData The data to be removed
      @return true if the item is removed,
              and false otherwise
   */
  public boolean remove(E outData) {
      
      boolean flag=false;
    if (head == null)
      return false;
    else if (head.data.equals(outData)) {
      head = head.next;
      flag=false;
      if(head.next==null)
      {
          flag=true;
      }
      if(flag==true)
      {
          return true;
      }
      return false;
    }
    /*
    if(head.next==null)
    {
        flag=true;
    }
    if(flag==true)
    {
        return true;
    }
*/
    else
      return remove(head.next, head, outData);
  }

}


