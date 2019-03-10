import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
/**
 * Testleri (Senaryolari deneyecegimiz ) Main
 */

/**
 * Created by macboookair on 27.03.2016.
 */
public class TestMain {

	public static void main(String... args) {

		//TowerOfHanoi ye ait obje olusturulup deger yollanarak donusum yapilacaktir
		NewTowerOfHanoi toh = new NewTowerOfHanoi(4);
		toh.execute();
		//RecursiveList e ait obje olusturulup elemanlar eklenerek listeden cikartilip cikartimayacagi gozlendi
		RecursiveList<Integer> a = new RecursiveList<>();

		a.add(5);
		a.add(6);
		a.add(4);
		a.add(4);
		a.add(3);
		a.add(4);
		a.add(5);
		a.add(4);
		System.out.println("Before :"+a);
		a.remove(4);
		System.out.println("After : "+a);

		//part3 icin list yapilarina gore karsilatırma yapilacak elemanlar  olusturuldu
		List<Integer> list1;
		List<Integer> list2;
		List<Integer> resultList;
		part3<Integer> deneme1 = new part3<>();
		list1 = new Stack<>();
		list2 = new Stack<>();
		resultList = new ArrayList<>();

		list1.add(1);
		list1.add(3);
		list1.add(8);
		list1.add(9);
		list1.add(23);
		list1.add(23);


		list2.add(1);
		list2.add(2);
		list2.add(8);
		list2.add(10);
		list2.add(34);


		System.out.println("1.List :"+list1);
		System.out.println("2.List :"+list2);
		deneme1.findCommonElement(list1,list2,resultList);

		System.out.print("Common :");
		for(int i=0;i<resultList.size();++i)
		{
			System.out.printf("%d -",resultList.get(i));
		}


		list1.clear();
		list1.add(1);
		list1.add(3);
		list1.add(8);
		list1.add(9);
		list1.add(23);
		list1.add(23);

		list2.clear();
		list2.add(1);
		list2.add(2);
		list2.add(8);
		list2.add(10);
		list2.add(34);
		resultList.clear();
		System.out.println("\n\n1.List :"+list1);
		System.out.println("2.List :"+list2);
		deneme1.unionOfList(list1,list2,resultList);
		System.out.print("Union :");
		for(int i=0;i<resultList.size();++i)
        {
            System.out.printf("%d - ",resultList.get(i));
        }


		list1.clear();
		list1.add(1);
		list1.add(3);
		list1.add(8);
		list1.add(9);
		list1.add(23);
		list1.add(23);

		list2.clear();
		list2.add(1);
		list2.add(2);
		list2.add(8);
		list2.add(10);
		list2.add(34);
		System.out.println("\n\n1.List :"+list1);
		System.out.println("2.List :"+list2);
		System.out.print("Subset : ");
		boolean expected = deneme1.isSubset(list1, list2);
		System.out.println(expected);
	}
}
