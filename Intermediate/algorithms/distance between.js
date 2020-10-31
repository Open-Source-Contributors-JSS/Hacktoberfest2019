const distanceBetween = coordinates =>
  {
  return Math.sqrt(Math.pow((coordinates[0][0] - coordinates[0][1]),2) + Math.pow((coordinates[1][0] - coordinates[1][1]),2));
  }

distanceBetween([[-23.627,-46.635],[-23.648,-46.588]]); // '32.490177961962594'