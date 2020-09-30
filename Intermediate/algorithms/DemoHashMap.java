package Intermediate.algorithms;

import java.util.HashMap;
import java.util.Map;

public class DemoHashMap {
    public static void main(String[] args) {
        // membuat HashMap
        HashMap<String, String> hm = new HashMap<>();
        HashMap<String, String> hm2 = new HashMap<>();

        // menambah elemen HashMap
        hm.put("Indonesia", "Rupiah");
        hm.put("America", "USD");
        hm.put("Malaysia", "Ringgit");

        // mengecek apakah HashMap kosong
        if (!hm.isEmpty()) {
            System.out.println("HashMap tidak kosong");

            // mencetak
            System.out.println("Nilai HashMap hm : ");
            for (Map.Entry hash : hm.entrySet()) {
                System.out.println(hash.getKey() + " -> " + hash.getValue());
            }
        }

        // menambah elemen ke hm2 dari elemen yang ada di hm1
        hm2.putAll(hm);

        // mencetah hm2
        System.out.println("Nilai HashMap m2 : ");
        for (Map.Entry hash2 : hm2.entrySet()) {
            System.out.println(hash2.getKey() + " -> " + hash2.getValue());
        }

        // mereplace salah satu elemen hm
        hm.replace("Amerika", "US Dollar");
        System.out.println("\nNilai hashmap hm setelah direplace : ");
        for (Map.Entry hash : hm.entrySet()) {
            System.out.println(hash.getKey() + " -> " + hash.getValue());
        }

        // mengecek apakah isi kedua hashmap sama
        if (hm.equals(hm2)) {
            System.out.println("Hashmap hm = Hashmap hm2");
        } else {
            System.out.println("Hashmap hm != Hashmap hm2");
        }

        // mencetak ukuran Hashmap
        System.out.println("\nUkuran awal Hashmap ini : " + hm.size());

        // menghapus salah satu elemen hashmap
        hm.remove("Malaysia");
        System.out.println("Ukuran hashmap hm setelah di remove : " + hm.size());
    }
}