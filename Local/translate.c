void	translate(double *coord1, double *coord2, double *result)
{
  result[0] = coord1[0] - coord2[0];
  result[1] = coord1[1] - coord2[1];
  result[2] = coord1[2] - coord2[2];
}
