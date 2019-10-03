import java.util.Iterator; 
import java.util.TreeSet;

public class TreeSet
{
	public static void main(String[] args)
	{
		TreeSet<Integer> ts = new TreeSet<Integer>();
		ts.add(10);
		ts.add(61);
		ts.add(87);
		ts.add(39);

		Iterator<Integer> iterator = ts.iterator();
		System.out.print("Tree set data: ");

		while (iterator.hasNext())
			System.out.print(iterator.next() + " ");
		System.out.println();

		if (ts.isEmpty())
			System.out.print("Tree Set is empty.");
		else
			System.out.println("Tree Set size: " + ts.size());

		System.out.println("First data: " + ts.first());

		System.out.println("Last data: " + ts.last());

		if (ts.remove(61))
			System.out.println("Data is removed from tree set");
		else
			System.out.println("Data doesn't exist!");

		System.out.print("Now the tree set contain: ");
		iterator = ts.iterator();

		while (iterator.hasNext())
			System.out.print(iterator.next() + " ");

		System.out.println();
		System.out.println("Now the size of tree set: " +
						ts.size());

		ts.clear();
		if (ts.isEmpty())
			System.out.print("Tree Set is empty.");
		else
			System.out.println("Tree Set size: " + ts.size());
	}
}
