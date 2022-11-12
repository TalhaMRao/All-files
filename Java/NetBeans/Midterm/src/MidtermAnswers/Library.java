/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MidtermAnswers;

/**
 *
 * @author fattanezarrinkalam
 */
import java.util.ArrayList;

public class Library {
    private String name;
    private final ArrayList<Book> books;

    public Library() {
        this.name = "";
        this.books = new ArrayList<>(1000);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void addBooks(Book book) {
        if (books.size() + 1 < 1001) {
            books.add(book);
        } else {
            System.out.println("Library capacity will exceed.");
        }
    }

    public ArrayList<Book> searchBooks(String keyword) {
        ArrayList<Book> searchedBooks = new ArrayList<>();
        if (!books.isEmpty()) {
            for (int i = 0; i < books.size(); i++) {
                if (books.get(i).getTitle().toLowerCase().contains(keyword.toLowerCase())) {
                    searchedBooks.add(books.get(i));
                }
            }
        } else {
            System.out.println("Library has no books with " + keyword + ".");
        }
        return searchedBooks;
    }

    public String getName() {
        return name;
    }

    public ArrayList<Book> getBooks() {
        return books;
    }
}


