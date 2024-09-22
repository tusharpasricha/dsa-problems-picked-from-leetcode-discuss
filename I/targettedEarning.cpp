public static int[] findMinHours(int peakPrice, int nonPeakPrice, int target) {
        int []res = new int[2];
        int targetForOne = target / 10;
        if (peakPrice > nonPeakPrice) {
            res[0] = targetForOne / peakPrice;
            targetForOne %= peakPrice;
            res[1] = targetForOne / nonPeakPrice;
        } else {
            res[1] = targetForOne / nonPeakPrice;
            targetForOne %= peakPrice;
            res[0] = targetForOne / peakPrice;
        }
        return res;
}