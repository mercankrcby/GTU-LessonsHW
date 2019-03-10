import java.util.List;

/**
 * Classin Amaci:Ortak olan elemanlari bulup dondurmek //intersection
 * Listelerin birlesimlerini yapmak //union
 * Alt kumesi olup olmadigini belirlemek
 */

/**
 * Created by macboookair on 27.03.2016.
 */
public class part3<E> {

	/**
	 * Intersection :Kesisim
	 * ortak olan elemanlar yeni liste halinde return edilir
	 * @param list1  1.listeyi alir
	 * @param list2  2.listeyi alir
	 * @param resultArray sonuc arrayini return eder
     * @return List
     */
	public List<E> findCommonElement(List<E> list1, List<E> list2, List<E> resultArray) {
		if (list1.isEmpty()) {
			return resultArray;
		}
		E element = list1.get(0);
		if (list1.size() != 0) {
			list1.remove(0);
		}
		if (list2.contains(element)) {
			resultArray.add(element);
		}
		return findCommonElement(list1, list2, resultArray);


	}

	/**
	 * Union :Birlesim
	 * listelerin birlesimlerini saglar
	 * @param list1 List 1.Listeyi alir
	 * @param list2 List 2.Listeyi alir
	 * @param resultArray sonuc arrayini return eder
     * @return List
     */
	public List<E> unionOfList(List<E> list1, List<E> list2, List<E> resultArray) {

		if (list2.isEmpty() && list1.isEmpty()) {
			return resultArray;
		}

		if (!list1.isEmpty()) {
			if (list2.contains(list1.get(0))) {
				list2.remove(list2.indexOf(list1.get(0)));
				list1.remove(0);
			} else {
				if (!resultArray.contains(list1.get(0))) {
					resultArray.add(list1.get(0));
				}
				list1.remove(0);
			}
			return unionOfList(list1, list2, resultArray);
		}
		if (!list2.isEmpty()) {
			if (resultArray.contains(list2.get(0))) {
				list2.remove(0);
			} else {
				if (!resultArray.contains(list2.get(0))) {
					resultArray.add(list2.get(0));
				}
				list2.remove(0);
			}

			return unionOfList(list1, list2, resultArray);
		}
		return unionOfList(list1, list2, resultArray);

	}

	/**
	 * Subset :Alt Kume
	 * @param list1 List 1.Listeyi alir
	 * @param list2 List 2.Listeyi alir
     * @return boolean
     */
	public boolean isSubset(List<E> list1, List<E> list2) {

		if (list1.isEmpty()) {
			return true;
		}

		if (list2.contains(list1.get(0))) {
			list1.remove(0);
			return isSubset(list1, list2);
		}
		return false;
	}

}
