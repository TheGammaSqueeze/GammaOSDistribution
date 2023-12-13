/*******************************************************************************
 * Copyright (c) 2009, 2019 Mountainminds GmbH & Co. KG and Contributors
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Marc R. Hoffmann - initial API and implementation
 *    
 *******************************************************************************/
package org.jacoco.agent.rt.internal;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.channels.FileChannel;
import java.nio.ByteBuffer;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import org.jacoco.core.data.ExecutionData;
import org.jacoco.core.data.ExecutionDataWriter;
import org.jacoco.core.data.ExecutionDataDelegate;
import org.jacoco.core.data.IExecutionData;
import org.jacoco.core.data.ExecutionDataStore;
import org.jacoco.core.data.MappedExecutionData;
import org.jacoco.core.runtime.AgentOptions;
import org.jacoco.core.runtime.RuntimeData;

/**
 * The API for classes instrumented in "offline" mode. The agent configuration
 * is provided through system properties prefixed with <code>jacoco.</code>.
 */
public final class Offline {

	// BEGIN android-change
	// private static final RuntimeData DATA;
	private static final Map<Long, ExecutionDataDelegate> DATA = new HashMap<Long, ExecutionDataDelegate>();
	private static FileChannel CHANNEL;
	// END android-change
	private static final String CONFIG_RESOURCE = "/jacoco-agent.properties";

	// BEGIN android-change
	// static {
	//	 final Properties config = ConfigLoader.load(CONFIG_RESOURCE,
	//			System.getProperties());
	//	 DATA = Agent.getInstance(new AgentOptions(config)).getData();
	// }
	// END android-change

	private Offline() {
		// no instances
	}

	// BEGIN android-change
	/**
	 * API for offline instrumented classes.
	 * 
	 * @param classid
	 *            class identifier
	 * @param classname
	 *            VM class name
	 * @param probecount
	 *            probe count for this class
	 * @return IExecutionData instance for this class
	 */
	public static IExecutionData getExecutionData(final long classid,
			final String classname, final int probecount) {
		// return DATA.getExecutionData(Long.valueOf(classid), classname,
		//		probecount).getProbes();
		synchronized (DATA) {
			ExecutionDataDelegate entry = DATA.get(classid);
			if (entry == null) {
				entry = new ExecutionDataDelegate(
						classid, classname, probecount, CHANNEL);
				DATA.put(classid, entry);
			} else {
				entry.assertCompatibility(classid, classname, probecount);
			}
			return entry;
		}
	}

	/**
	 * Enables memory-mapped execution data and converts existing
	 * {@link ExecutionDataDelegate}s.
	 */
	public static void enableMemoryMappedData() {
		try {
			prepareFile(getPid());
			for (ExecutionDataDelegate data : DATA.values()) {
				data.convert(CHANNEL);
			}
		}  catch (IOException e) {
			// TODO(olivernguyen): Add logging to debug issues more easily.
		}
	}

	/**
	 * Creates the output file that will be mapped for probe data.
	 */
	private static void prepareFile(int pid) throws IOException {
		// Write header information to the file.
		ByteBuffer headerBuffer = ByteBuffer.allocate(5);
		headerBuffer.put(ExecutionDataWriter.BLOCK_HEADER);
		headerBuffer.putChar(ExecutionDataWriter.MAGIC_NUMBER);
		headerBuffer.putChar(ExecutionDataWriter.FORMAT_VERSION);
		headerBuffer.flip();

		// If this file already exists (due to pid re-usage), the previous coverage data
		// will be lost when the file is overwritten.
		File outputFile = new File("/data/misc/trace/jacoco-" + pid + ".mm.ec");
		CHANNEL = new RandomAccessFile(outputFile, "rw").getChannel();
		synchronized (CHANNEL) {
			CHANNEL.write(headerBuffer);
		}
	}

	/**
	 * Helper function to determine the pid of this process.
	 */
	private static int getPid() throws IOException {
		// Read /proc/self and resolve it to obtain its pid.
		return Integer.parseInt(new File("/proc/self").getCanonicalFile().getName());
	}
	// END android-change

	/**
	 * Creates a default agent, using config loaded from the classpath resource and the system
	 * properties, and a runtime data instance populated with the execution data accumulated by
	 * the probes up until this call is made (subsequent probe updates will not be reflected in
	 * this agent).
	 *
	 * @return the new agent
	 */
	static Agent createAgent() {
		final Properties config = ConfigLoader.load(CONFIG_RESOURCE,
				System.getProperties());
		synchronized (DATA) {
			ExecutionDataStore store = new ExecutionDataStore();
			for (IExecutionData data : DATA.values()) {
				store.put(data);
			}
			return Agent.getInstance(new AgentOptions(config), new RuntimeData(store));
		}
	}
	// END android-change
}
