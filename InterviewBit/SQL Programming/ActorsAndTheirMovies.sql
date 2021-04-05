SELECT DISTINCT movie_title FROM movies_cast NATURAL JOIN movies WHERE actor_id IN (SELECT actor_id FROM movies_cast GROUP BY actor_id HAVING COUNT(*) >= 2);
