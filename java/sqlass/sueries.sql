
select tbl_book.bookId , title , tbl_book_copies.branchId , noOfCopies , branchName from tbl_book join tbl_book_copies join tbl_library_branch on tbl_book_copies.bookId = tbl_book.bookId and tbl_library_branch.branchId = tbl_book_copies.branchId where title LIKE 'The Lost Tribe' and branchName Like "Sharpstown";

select tbl_book.bookId , title , tbl_book_copies.branchId , noOfCopies , branchName from tbl_book join tbl_book_copies join tbl_library_branch on tbl_book_copies.bookId = tbl_book.bookId and tbl_library_branch.branchId = tbl_book_copies.branchId where title = 'The Lost Tribe';


select title , tbl_borrower.name (select bookId , cardNo from tbl_book_loans join (select branchId , branchName from tbl_library_branch where branchName = "Sharpstown") as fs on fs.branchId = tbl_book_loans.branchId where dueDate > '2018-03-10 00:00:00') as ss inner join tbl_book on ss.bookId , tbl_book.bookId inner join tbl_borrower on ss.cardNo = tbl_borrower.cardNo;