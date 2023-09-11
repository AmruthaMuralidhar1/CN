#include <stdio.h>
#include <stdbool.h>

#define BUCKET_SIZE 10 // Bucket size
#define OUTPUT_RATE 1 // Output rate (packets per second)

int main() {
    int input_pkt_size;
    int bucket_level = 0;
    bool active = false;

    printf("Enter the input packet size (0 to exit): ");

    while (1) {
        scanf("%d", &input_pkt_size);

        if (input_pkt_size == 0) {
            printf("Exiting the program.\n");
            break;
        }

        // Add incoming packets to the bucket
        bucket_level += input_pkt_size;

        // If the bucket is full, drop excess packets
        if (bucket_level > BUCKET_SIZE) {
            printf("Packet dropped: Bucket overflow\n");
            bucket_level = BUCKET_SIZE;
        } else {
            printf("Packet added: %d\n", input_pkt_size);
        }

        // If there are packets in the bucket, send them
        if (bucket_level >= OUTPUT_RATE) {
            printf("Packet sent: %d\n", OUTPUT_RATE);
            bucket_level -= OUTPUT_RATE;
            active = true;
        } else {
            active = false;
        }

        // Display the current bucket level
        printf("Bucket level: %d\n", bucket_level);

        if (active) {
            printf("Bucket is active.\n");
        } else {
            printf("Bucket is idle.\n");
        }

        printf("Enter the input packet size (0 to exit): ");
    }

    return 0;
}
