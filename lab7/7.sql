SELECT AVG(energy) FROM songs AS s
JOIN artists AS a ON a.id = s.artist_id
WHERE a.name = "Drake";