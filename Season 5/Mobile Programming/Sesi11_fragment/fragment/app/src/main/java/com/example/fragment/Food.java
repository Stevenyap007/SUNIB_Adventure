package com.example.fragment;

public class Food {
    String name;
    String desc;

    public static  final Food[] foods = {
            new Food("Nasi Goreng","Seafood\nTelor Dadar\nAcar"),
            new Food("Bubur Ayam","Ayam Suwir\nCakwe\nKacang"),
            new Food("Nasi Uduk","Telor Bulat\nTahu\nTempe"),
    };

    public Food(String name, String desc){
        this.name = name;
        this.desc = desc;
    }

    public String getName() {
        return name;
    }

    public String getDesc() {
        return desc;
    }

    public String toString(){
        return this.name;
    }

}
