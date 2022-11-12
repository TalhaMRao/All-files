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

public class Book {
    public static int BOOK_ID = 0;
    private final int id;
    private String title;
    private final ArrayList<Author> authors;

    public Book() {
        ++BOOK_ID;
        this.id = BOOK_ID;
        this.title = "No Title";
        authors = new ArrayList<>(10);
    }

    public boolean setTitle(String title) {
        if (title.length() > 4 && title.length() < 51) {
            this.title = title;
            return true;
        } else {
            System.out.println("Too lengthy title.Try again.");
            return false;
        }
    }

    public void addAuthors(Author author) {
        if (authors.size() + 1 < 11) {
            authors.add(author);
        } else {
            System.out.println("Too many authors.");
        }
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public ArrayList<Author> getAuthors() {
        return authors;
    }
}
