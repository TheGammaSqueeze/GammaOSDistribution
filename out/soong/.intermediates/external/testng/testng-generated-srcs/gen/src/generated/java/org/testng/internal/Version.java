package org.testng.internal;

public class Version {
  public static final String VERSION = "6.9.10-SNAPSHOT";

  public static void displayBanner() {
    System.out.println("...\n... TestNG " + VERSION + " by Cédric Beust (cedric@beust.com)\n...\n");
  }
}
