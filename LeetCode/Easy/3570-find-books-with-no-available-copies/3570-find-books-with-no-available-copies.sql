SELECT
  lb.book_id,
  lb.title,
  lb.author,
  lb.genre,
  lb.publication_year,
  COUNT(*) AS current_borrowers
FROM
  library_books lb
JOIN
  borrowing_records br ON lb.book_id = br.book_id
WHERE
  br.return_date IS NULL
GROUP BY
  lb.book_id, lb.title, lb.author, lb.genre, lb.publication_year, lb.total_copies
HAVING
  COUNT(*) = lb.total_copies
ORDER BY
  current_borrowers DESC, title ASC;
